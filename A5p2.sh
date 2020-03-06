#!/bin/bash

i=$1
count=1
echo -n $i

while [ $i -ne 1 ]
do
	if [ $(( i % 2 )) -eq 0 ]; then
		((i = i / 2))
	else
		((i = ((3 * i) + 1) / 2))
	fi
echo -n " "$i
((count = count + 1))
done
echo 
echo Length of the sequence: $count


