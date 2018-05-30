#!/bin/bash

# http://www.cs.ubbcluj.ro/~rares/course/os/res/osvm/2018/lab-05/content.txt
# pr3

sum=0

for i in `ls -i | awk '{print $1}'`; do
	(( sum += $i ))
done

echo $sum
