#!/bin/bash

dirName=$1

for f in `find $dirName -type f`; do
	name=`echo $f | sed 's@.*/@@'`
	fLen=${#name}
	
	if [ $fLen -lt 8 ]; then
		echo $f $fLen
	fi
done
~/Desktop/OS/lab6_hw$
