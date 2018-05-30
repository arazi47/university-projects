#!/bin/bash

# http://www.cs.ubbcluj.ro/~rares/course/os/res/osvm/2018/lab-05/content.txt
# pr2

for f in `find /usr/bin/ -type f`; do
	if `file $f | grep -q ERF`; then
		echo $f
	fi
done
