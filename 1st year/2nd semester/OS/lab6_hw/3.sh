#!/bin/bash

dirName=$1

for file in `find $dirName -type f`; do
	lines=`cat $file | wc -l`
	if [ $lines -lt 11 ]; then
		cat $file
	else
		cat $file | head -n 5
		cat $file | tail -n 5
	fi
	echo ----- END -----
done
