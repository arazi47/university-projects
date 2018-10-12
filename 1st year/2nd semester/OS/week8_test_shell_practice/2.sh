#!/bin/bash

# argument: directory name
# find all directories in given directory name
# check if 2 consecutive directories have the same size

dirName=$1
lastDir='/dev/null'
lastDirSz=0
for dir in `find $dirName -type d`; do
	lastDirSz=`du -s $lastDir | cut -f 1`
	dirSz=`du -s $dir | cut -f 1`

	if [ $lastDirSz -eq $dirSz ]; then
		echo $lastDir has same size as $dir
	fi

	lastDir=$dir
	lastDirSz=$dirSz
done

