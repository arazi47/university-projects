#!/bin/bash

# args: words
# read files until all given words have been found in files

totalArgs=$#

WORDS=()
for arg in $@; do
	WORDS+=($arg)
done

cnt=0

while true; do
	read file
	
	# trebuie length -= 1 pentru ca arata numarul total de elemente, nu ultimul index
	length=${#WORDS[@]}
	(( length -= 1 ))
	for index in `seq 0 $length`; do
		if cat $file | grep -q "${WORDS[index]}"; then
			#echo $index yes now len is ${#WORDS[@]}-1
			unset WORDS[$index]
			(( cnt += 1 ))

			if [ $cnt -eq $totalArgs ]; then
				exit
			fi
		fi
	done
done

