#!/bin/bash

dirName=$1

for file in `find $dirName -type f`; do
	if cat $file | grep -q '[0-9]\{5,\}'; then
		echo $file
	fi
done
