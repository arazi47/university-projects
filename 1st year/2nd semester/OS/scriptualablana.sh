#!/bin/bash

# param cuv + lista de fisiere. sa se numere fisierele in care apare cuvantul

nume=$1
shift
cnt=0

for i in $*; do
	if cat $i | grep -q $nume; then
		(( cnt += 1 ))
	fi
done

echo $cnt

