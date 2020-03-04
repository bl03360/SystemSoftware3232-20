#!/bin/bash

printProduct(){
let i=$1
let j=$2
let k=i*j
echo $i "*" $j = $k
}

for (( i = 1; i <= 3; i++))
do
	for (( j = 1; j <= 5; j++))
	do
	printProduct i j
	done
done