#!/bin/bash

# arg can be anything
# if arg is digit and < 50, prod *= arg
# if arg is directory, count all .sh files in it
# if arg is not digit and not directory, do nothing

prod=1

for arg in $*; do
	if echo $arg | grep -q "[[:digit:]]" && [ $arg -lt 50 ]; then
		(( prod *= $arg ))
	elif [ -d $arg ]; then
		echo $arg contains `ls $arg | grep -c .sh$` .sh files.
	fi
done

echo Prod is $prod.

