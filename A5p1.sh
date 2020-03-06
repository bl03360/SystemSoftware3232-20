#!/bin/bash

if [ -z $1 ]; then 
echo "usage: " $0 "<directory>"
exit
fi

num_execFiles=0
num_nonexecFiles=0
num_subDir=0

for entry in $1/*
do		
	if [ -f $entry ]; then
		if [ -x $entry ]; 
			then 
			((num_execFiles = num_execFiles + 1))
		else
			((num_nonexecFiles = num_nonexecFiles + 1))
		fi
	else
		((num_subDir = num_subDir + 1))
	fi
done
echo Number of executable files in $1: $num_execFiles
echo Number of non-executable files in $1: $num_nonexecFiles
echo Number of subdirectories in $1: $num_subDir 
	

