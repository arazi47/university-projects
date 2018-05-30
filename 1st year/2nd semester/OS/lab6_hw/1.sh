#!/bin/bash

dirName=$1
sum=0
files=0

for file in `find $dirName -type f`; do
	if file $file | grep -q "ASCII text"; then
		lines=`cat $file | wc -l`
		(( sum += lines ))
		(( files += 1 ))
	fi
done

echo $(( sum / files ))
