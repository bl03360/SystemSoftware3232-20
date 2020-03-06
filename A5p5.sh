#!/bin/bash

i=1
while [ $i -lt $1 ]
do	
	echo $i
	((i = i + 2))
done

