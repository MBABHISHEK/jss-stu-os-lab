#1/bin/bash

echo "ENTER THE NUMBER OF ELEMENTS OF THE ARRAY"
read n

declare -A arr;
echo "ENTER THE ELEMENTS TO THE ARRAY"

for ((i=0; i<n; i++))
do
   read arr["$i"];
done


max=${arr[0]}

for ((i=1; i<n; i++))
do
   if (( "$arr[$i]" -gt "$max" )); 
   then
        max=${arr[$i]}
    fi
 done

 echo "THE LAEGEST VALUE IN THE ARRAY>> $max"   



