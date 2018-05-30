#!/bin/bash

dirName=$1

for f in `find $dirName -type f -perm 0755`; do
	echo -n "Do you want to modify this? (y/n) "
	read confirmation

	if [ $confirmation = "y" ]; then
		echo Yes for $f.
	elif [ $confirmation = "n" ]; then
		echo No for $f.
	fi
done

