#!/bin/bash

declare -i cnt=0
declare -i sum=0

# average lines per file, dir is an argument

for f in $(find $1 -type f); do
	if file $f | grep -q 'ASCII'; then
		lines=`cat $f | wc -l`
		sum=$(($sum+$lines))
		cnt=$((cnt+1))
	fi
done

echo "Count: " $cnt "; Sum: " $sum "; Average: " $(($sum/$cnt))
