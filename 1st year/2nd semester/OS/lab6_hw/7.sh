#!/bin/bash

for file in $*; do
	cat $file | sort | uniq -c | sort -n | sort -r | head -n 1 | cut -c9-
done

