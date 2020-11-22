module Tree
    type tree<'a> =
        | Empty
        | Leaf of 'a
        | Node of 'a * (tree<'a> list)

    let concat t r = 
        match t with 
        | Empty -> r
        | Leaf(v) -> Node(v,[r])
        | Node(v,children)-> Node(v,r::children)
    let rec length t =
        match t with
        | Empty -> 0
        | Leaf(_) -> 1
        | Node(v,children) -> 1 + (children |> List.map (fun n -> length n) |> List.max)
    let rec map t trans = 
        match t with
        | Empty -> Empty
        | Leaf(value) -> Leaf(trans(value))
        | Node(value,children) -> Node(trans(value),children |> List.map (fun n -> map n trans));
    let rec flatten t = 
        seq { 
            match t with
                | Empty -> ignore t
                | Leaf(v) -> yield t
                | Node(v,children) -> 
                    yield t
                    for n in children do yield! flatten n 
            }
    let filter t pred =
        t |> flatten |> Seq.filter pred
    let fold t pred = 
        t |> flatten |> Seq.map (fun n -> match n with Leaf(v) | Node(v,_) -> v | Empty -> ignore n) |> Seq.fold pred
    let rec traverse t func = 
        match t with 
        | Leaf(v) -> 
            func(v)
        | Node(v,children) ->
            func v
            children |> List.iter (fun i -> traverse i func)
        | _ -> ignore t
    let add t n = 
        match n with 
        | Empty -> t
        | _ ->
            match t with 
            | Leaf(v)-> Node(v,[n])
            | Node(v,children)-> Node(v,n::children)
            | _ -> n
    let all t pred = 
        t |> flatten |> Seq.forall pred
    let rec any t pred = 
        match t with
        | Empty -> false
        | Leaf(value) -> 
            match pred value with
            | Some(v) -> true
            | _ -> false
        | Node(value,children) ->
            match pred value with
            | Some(v) -> true
            | _ -> 
                let len = children |> List.where (fun i -> any i pred) |> List.length
                match len with 
                | 0 -> false
                | _ -> true
    let rec find t p = 
        t |> flatten |> Seq.find p
    let contains t n = 
        t |> flatten |> Seq.contains n
    let remove t pred = failwith "not yet made"
    let rec iter t func = 
        match t with
        | Node(value,children) -> 
            func(value)
            for child in children do 
                iter child func
        | Leaf(value) -> 
            func(value)
        | _ -> ignore t