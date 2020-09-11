open System
//input logic
let getInput = Console.ReadLine()
let readLines = Seq.initInfinite (fun _ -> Console.ReadLine()) |> Seq.takeWhile (String.IsNullOrWhiteSpace >> not)
[<EntryPoint>]
let main argv = 
    let n = getInput |> int
    let filtr limit = readLines |> Seq.map int |> Seq.filter ((>)limit)
    filtr n |> Seq.iter(printfn "%A")
    0 // return an integer exit code