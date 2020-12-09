open System

(*USER CODE BEGIN*)
let add a b = a + b
let sum arr = 
    let mutable totalsum = 0
    for i in arr do
        totalsum <- add totalsum i
    totalsum
let isOdd n = n % 2 <> 0
let f arr = sum(List.filter (isOdd) arr)
(*USER CODE END*)

let read_and_parse()=
    let mutable arr = []
    let mutable buff = Console.ReadLine()
    while buff <> null do
            arr <- Int32.Parse(buff)::arr
            buff <- Console.ReadLine()
    arr

let main =    
    let arr = read_and_parse()
    printf "%A" <| f arr