#!/bin/bash
for (( i = 1; i <= 3; i++))
do
	for (( j = 1; j <= 5; j++))
	do
		let k=i*j
		echo $i "*" $j = $k
	done
done
