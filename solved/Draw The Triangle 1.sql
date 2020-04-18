declare @i INT = 20
while(@i>0)
    begin
        print replicate("* ",@i)
        set @i=@i-1
    end