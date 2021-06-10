open System
open FSharp.Core
    
[<AutoOpen>] module Utils = 
    let (?) condition (opt1, opt2) = 
        if condition then 
            opt1 
        else opt2

    let toHex bytes = 
        bytes 
        |> Array.map (fun (x : byte) -> System.String.Format("{0:X2}", x))
        |> String.concat System.String.Empty

    let fromHex (s:string) = 
        s
        |> Seq.windowed 2
        |> Seq.mapi (fun i j -> (i,j))
        |> Seq.filter (fun (i,j) -> i % 2=0)
        |> Seq.map (fun (_,j) -> Byte.Parse(new System.String(j),System.Globalization.NumberStyles.AllowHexSpecifier))
        |> Array.ofSeq

    let shift r (byteArr:uint16 array) =
        let bytesList = byteArr |> Array.toList
        let bytes, bits, size =  r / 16, r % 16, List.length bytesList
        let rotatedByBlock = 
            let block = bytesList.[.. bytes - 1]
            let bytesList' = bytesList.[bytes ..] @ block
            bytesList'
        let rotatedByRemBits = 
            rotatedByBlock
            |> List.mapi (fun i _ -> 
                    let left = rotatedByBlock.[i] <<< bits
                    let right= (16 - bits = 16) ? (0us, rotatedByBlock.[(i + 1) % size] >>> (16-bits))
                    left ||| right
                )
        rotatedByRemBits
        |> List.toArray
    let (<<<=) a b = shift b a 

    let toUint16 arr = arr |> Array.chunkBySize 2 
                               |> Array.map (fun [|l; r|] -> 
                                    let l', r' = uint16 l, uint16 r
                                    (l' <<< 8) ||| r' )

    let toByte arr = arr |> Array.map (fun i -> 
                                    [|i >>> 8; i|])
                               |> Array.concat
                               |> Array.map byte

    let inline modulo b a = (a % b + b) % b
    let inline (%.) a b = modulo b a

[<AutoOpen>] module Arithmetic = 
       
    let Add (a:uint16) (b:uint16) = (a + b) &&& 0xFFFFus
    let ( +. ) = Add 
    
    let Mul (a:uint16) (b:uint16) = 
        let r = (uint64 a) * (uint64 b)
        if  r = 0UL then  
            (1us - a - b) &&& 0xFFFFus
        else
            r
            |> modulo 0x10001UL
            |> ((&&&) 0xFFFFUL)
            |> uint16
    let ( *. ) = Mul

    let AddInv (x':uint16) = 
        let x = int x'
        (0x10000 - x) &&& 0xFFFF
        |> uint16
    let ( !+ ) = AddInv 

    let MulInv (x':uint16) = 
        let x = x' |> (int >> ((&&&)0xFFFF))
        let r = match x <= 1 with 
                | true -> x
                | _ -> 
                    let init = 0x10001
                    let rec Pgcd (old_r, r) (old_s, s) =
                        match r with 
                        | 0 -> 
                            old_s %. init
                        | _ -> 
                            let quotient' = old_r / r
                            let (old_r', r') = (r, old_r - quotient' * r) 
                            let (old_s', s') = (s, old_s - quotient' * s) 
                            Pgcd (old_r', r') (old_s', s')
                    Pgcd (init, x) (0, 1)
        r |> uint16
    let ( !* ) = MulInv
 
module IDEA =
    let rounds = 8
    type IDEA = {
        keys : (uint16[]) *  (uint16[])
    }
    type Mode = Encryption | Decryption

    let invert (key:uint16 [][]) = 
        let keys =  key 
                    |> Array.concat
        let rec generate round acc =
            let beggining = (round = 8 ) ? (0, 4 + (8 - round - 1) * 6)
            if round = rounds then
                ([|
                    !* keys.[beggining + 0]
                    !+ keys.[beggining + 1]
                    !+ keys.[beggining + 2]
                    !* keys.[beggining + 3]
                |]::acc)
                |> List.toArray
                |> Array.rev
            else
                let j, k = (round > 0) ? ((4, 3),(3, 4))
                generate (round + 1) ([|
                    !* keys.[beggining + 2]
                    !+ keys.[beggining + j]
                    !+ keys.[beggining + k]
                    !* keys.[beggining + 5]
                    keys.[beggining + 0]
                    keys.[beggining + 1]
                |]::acc)
        generate 0 []

    let extract (key:byte[]) = 
        let size = Array.length key
        if size = 16 then 
            let subkeys = 
                key |> toUint16
            let enkeys = 
                [|
                    for i in 0..6 do
                        yield (subkeys <<<= (i * 25))
                |]  |> Array.mapi (fun i arr -> 
                        if i <> 6 then arr else arr.[1..4])
                    |> Array.concat 
                    |> Array.skip 8
                    |> Array.chunkBySize 6
            let dekeys = 
                invert enkeys
            Ok ([enkeys; dekeys] |> List.map (Array.concat))
        else 
            Error "Failed : key size must be 128bit | 16byte"

    let create key = 
        match extract key with 
        | Ok [en; de] -> Some {
                keys = en, de
            }
        | _ -> None

    let digest data (keys:uint16 []) =
        let rec loop round (keys':uint16[]) (data:uint16[]) = 
            let idx = round * 6 
            let func = [Mul; Add; Add; Mul]
            match round with 
            | 8 -> 
                [|
                    data.[0] *. keys.[idx + 0]
                    data.[2] +. keys.[idx + 1]
                    data.[1] +. keys.[idx + 2]
                    data.[3] *. keys.[idx + 3]
                |] |> toByte
            | _ -> 
                let ys = [
                    for i in 0..3
                        -> func.[i] data.[i] keys'.[i + idx]
                ]
                let ts  = 
                    let t0 = (ys.[0] ^^^ ys.[2]) *. keys'.[idx + 4]
                    let t1 = (ys.[1] ^^^ ys.[3]) +. t0
                    let t2 = (t1 *. keys'.[idx + 5])
                    let t3 = (t0 +. t2)
                    [t0; t1; t2; t3]
                loop (round + 1) keys' [|
                    ys.[0] ^^^ ts.[2]
                    ys.[2] ^^^ ts.[2]
                    ys.[1] ^^^ ts.[3]
                    ys.[3] ^^^ ts.[3]
                |]
        loop 0 keys (data |> toUint16)

    let crypt data mode algo =
        let crypt' = digest data
        let enkeys, dekeys = algo.keys
        match mode with 
        | Encryption -> 
            crypt' enkeys
        | Decryption -> 
            crypt' dekeys

let main = 
    let key = fromHex "006400C8012C019001F4025802BC0320"
    let data = fromHex "05320A6414C819FA"
    let expected = "65BE87E7A2538AED"
    let algo = IDEA.create key
    match algo with 
        | Some r -> 
            let enrs = IDEA.crypt data IDEA.Encryption r
            let ders = IDEA.crypt enrs IDEA.Decryption r
            printf "%A" {|
                            Data           =  data 
                            Encryption_key =  fst r.keys 
                            Decryption_key =  snd r.keys  
                            Encrypted_Data =  enrs    
                            Decrypted_Data =  ders  
                        |}
        | None   ->  printf "Error Algo Mal-defined"
