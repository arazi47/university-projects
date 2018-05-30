#!/bin/bash

dirName=$1

for file in `find $dirName -type f`; do
	if ls -l $file | grep -q r..r..r; then
		mv $file $file.all
	fi
done

