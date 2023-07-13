#!/bin/bash

echo "ENTER THREE NUMBERS"
read num1
read num2
read num3

if [[ $num1 > $num2 ]]
 then  largest=$num1
else
  largest=$num2
fi

if [[ $largest < $num3 ]]
 then  largest=$num3
fi

echo "THE LARGEST OF THREE NUMBERS IS $largest"
