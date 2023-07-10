#!/bin/bash

echo "ENTER THE NUMBER"
read n
temp=$n
rev=0

while (($temp > 0))
 do
    r=$((temp%10))
    rev=$((rev*10+r))
    temp=$((temp/10))
 done

 if [ $rev -eq $n ];
 then echo "IT IS A PALINDROME"
 else echo "IT IS NOT A PALINDROME"
 fi
