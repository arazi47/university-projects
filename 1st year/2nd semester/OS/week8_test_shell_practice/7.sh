#!/bin/bash

for arg; do
	linii=$(cat $arg | wc -l)
	cuv=$(cat $arg | wc -w)
	num=$(cat $arg | grep -o "[0-9]" | wc -l)
	echo $arg: nr linii $linii, nr cuvinte $cuv, din care $num numere
done
