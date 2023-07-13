#!/bin/bash

echo "ENTER THE VALUES OF N AND M"
read n
read m
declare -A a
declare -A b
declare -A r

echo "ENTER THE ELEMENTS OF THE MATRIX A"
for ((i=0;i<n;i++))
do
   for ((j=0;j<m;j++))
do
    read a[$i,$j]
done

done

echo "ENTER THE ELEMENTS OF THE MATRIX A"
for ((i=0;i<n;i++))
do
   for ((j=0;j<m;j++))
do
    read b[$i,$j]
done

done

echo "ENTER THE ELEMENTS OF THE MATRIX A"
for ((i=0;i<n;i++))
do
   for ((j=0;j<m;j++))
do
    echo -ne "${a[$i,$j]} "
done
   echo -e "\n"
done
echo "ENTER THE ELEMENTS OF THE MATRIX B"
for ((i=0;i<n;i++))
do
   for ((j=0;j<m;j++))
do
    echo -ne "${b[$i,$j]} "
done
   echo -e "\n"
done
echo "THE ELEMENTS OF THE RESULTANT MATRIX IS"
for ((i=0;i<n;i++))
do
   for ((j=0;j<m;j++))
do
   c[$i,$j]=$((b[$i,$j]+a[$i,$j]))
    echo -ne "${c[$i,$j]} "
done
   echo -e "\n"
done

    
