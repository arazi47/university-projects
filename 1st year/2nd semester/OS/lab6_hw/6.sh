#!/bin/bash

while [ $# -gt 0 ]; do
	fileName=$1
	cuvant=$2
	nr=$3

	cnt=`cat $fileName | grep -o $cuvant | grep -c`
	

	if [ $cnt -ge $nr ]; then
		echo $fileName
	fi
	shift 3
done

