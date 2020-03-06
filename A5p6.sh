#!/bin/bash

i=26

while [ $i -lt 36 ]
do 
	echo "For input -> "$i	
	bash ./A5p2.sh $i 
	echo
	((i = i + 1))
	
done
