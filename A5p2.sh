#!bin/bash

i=$1

echo i

while [i -ne 1]
do
	if ((i%2==0));
		then i = $i/2
	else
		i = (((3*$1))+1/2)
echo i
done		