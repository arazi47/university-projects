#!/bin/bash

a=$1
while [[ $2 -gt 0 ]]; do
	b=$2
	while [[ $b -gt 0 ]]; do
		r=$(($a%$b))
		a=$b
		b=$r
	done
	shift
done

echo $a

