#!/bin/bash

# parcurge toate fisierele .c si .h si printeaza toate include-urile de biblioteci

for dir in $*; do
	if [[ -d $dir ]]; then
		for file in `find $dir -type f`; do
			if echo $file | grep -q ".*.h$" || echo $file | grep -q ".*.c$"; then
				cat $file | grep -o "^\(#include <.*>\)" # cauta #include <...>
				cat $file | grep -o "^\(#include<.*>\)" # cauta #includude<...>
			fi
		done
	fi
done

