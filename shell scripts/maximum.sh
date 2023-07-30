#!/bin/bash

echo "ENTER THE NUMBER OF ELEMENTS OF THE ARRAY"
read n

declare -a arr;  # Corrected from declare -A to declare -a for indexed array
echo "ENTER THE ELEMENTS TO THE ARRAY"

for ((i=0; i<n; i++))
do
    read arr["$i"]
done

max=${arr[0]}

for ((i=1; i<n; i++))
do
    if (( ${arr[i]} > max )); # Corrected from "$arr[$i]" to ${arr[i]}
    then
        max=${arr[i]}
    fi
done

echo "THE LARGEST VALUE IN THE ARRAY: $max"
