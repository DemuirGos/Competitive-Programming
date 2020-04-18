declare @i INT =1
while(@i<=20)
    begin
        print replicate("* ",@i)
        set @i=@i+1
    end