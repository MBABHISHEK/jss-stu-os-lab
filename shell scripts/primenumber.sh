#!/bin/bash

echo "ENTER THE RANGE"
read n
flag=0

echo "THE PRIME NUMBERS FROM 1 TO $n ARE "

for ((i=2;i<n;i++))
do 
    for ((j=2;j<=$((i/2));j++))
     do
       if [[ $(($i%$j)) -eq 0 ]]; 
       then  
           flag=1
           break
        fi
    done

    if [[ "$flag" -eq 0 ]];
    then
        echo "$i"
     fi
     flag=0          
 done    