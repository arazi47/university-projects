#!/bin/bash

# copy contents from dirName to dirNameTo
# not really working correctly (for example, it doesn't work for dirs in dirs - it just puts them all in the same dir)

dirName=$1
dirNameTo=$2
for file in `find $dirName | tac | sed '$d'`; do
	fileName=$(echo $file | sed 's@.*/@@')
	echo $file $fileName
	cp -r $file $dirNameTo/$fileName.back
done
