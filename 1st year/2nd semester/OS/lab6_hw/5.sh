#!/bin/bash

for file in $*; do
	if file $file | grep -q "directory"; then
		cnt=0

		for i in `find $file`; do
			(( cnt += 1 ))
		done

		echo Directory $file has $cnt directories/subdirectories.
	else
		lines=$(cat $file | wc -l)
		chars=$(cat $file | wc -m)
		echo $file has $lines lines and $chars characters.
	fi
done

