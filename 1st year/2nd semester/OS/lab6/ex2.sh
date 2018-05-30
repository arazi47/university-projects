#!/bin/bash

for f in `find $1 -type f`; do
	if cat $f | grep -q '[0-9]\{5,\}'; then
		echo $f	| sed 's/.*\///'
	fi
done
