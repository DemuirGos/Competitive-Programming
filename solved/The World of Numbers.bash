read x
read y

for i in {+,-,"*",/}
do  
    echo $(((x)$i(y)))
done
