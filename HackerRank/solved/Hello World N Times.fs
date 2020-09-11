open System
let great greeting = printfn "%s" greeting
let loop n = for int i = 0 to n - 1  do great "Hello World"
let getInput = Console.ReadLine()
[<EntryPoint>]
let main argv = 
    let n = getInput |>int
    loop n
    0 // return an integer exit code
