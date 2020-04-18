module solution
    sub main()
        dim t as integer
        t=Convert.ToInt32(Console.ReadLine())
        dim k as integer
        for k=1 to t
            dim s() as string
            dim a as integer
            dim k as integer
            dim m as integer = 0
            dim i,j as integer
            s=Console.ReadLine().split()
            a=Convert.ToInt32(s(0))
            k=Convert.ToInt32(s(1))
            for i=1 to a-1 step 1
                for j=i+1 to a step 1
                    dim t as integer
                    t=i and j
                    if t>m and k>t then
                        m=t
                    end if
                next
            next
            Console.WriteLine(m)
        next 
    end sub
end module
