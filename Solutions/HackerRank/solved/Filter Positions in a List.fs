open System
//input logic
let readLines = Seq.initInfinite (fun _ -> Console.ReadLine() ) |> Seq.takeWhile (String.IsNullOrWhiteSpace >> not)
let indexSeq sequence = sequence |> Seq.indexed
let isOddIndexed (idx,item) = idx % 2 <> 0
let printItem (idx,item) = printfn "%A" item
[<EntryPoint>]
let main argv = 
    let result = readLines |> Seq.map int |> indexSeq |> Seq.filter isOddIndexed |> Seq.iter(printItem)
    0 // return an integer exit code