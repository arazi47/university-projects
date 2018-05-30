#!/bin/bash

dirName=$1
num=$2
username=$3

# args: directory, number, username
# prints the name of the N largest text files frm the given directory and its subdirs, sorted by their dimension in decreasing order
# prints the number of lines for each file
# check if the files are owned by username

IFS=$'\n'
for F in `find $dirName -type f -exec du -a {} + | sort -nr | head -$num`; do
	filePath=$(echo $F | awk '{print $2}')
	lines=$(cat $filePath | wc -l)
	echo -n "$F lines: $lines "
	
	if ls -l $filePath | awk '{print $3}' | grep -q $username; then
		echo owned by $username
	else
		echo not owned by $username
	fi
done
IFS=$' '

