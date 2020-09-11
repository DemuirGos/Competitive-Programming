open System
let write x = printfn "%s" x
let repeat n x = for int i = 0 to n - 1 do write x
let logic n lst = for i in lst do repeat n i
//input logic
let getInput = Console.ReadLine()
let readLines = Seq.initInfinite (fun _ -> Console.ReadLine()) |> Seq.takeWhile (String.IsNullOrWhiteSpace >> not) |> Seq.toList 
[<EntryPoint>]
let main argv = 
    let n = getInput |> int
    let l = readLines
    logic n l
    0 // return an integer exit code