#!/bin/bash

# http://www.cs.ubbcluj.ro/~rares/course/os/res/osvm/2018/lab-05/content.txt
# pr1

cmd=""
for i in $*; do
	if [ $i == '!' ]; then
		$cmd
		cmd=""
	else
		cmd+=" "
		cmd+=$i
	fi
done
