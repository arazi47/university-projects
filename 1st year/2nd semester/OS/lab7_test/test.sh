# scrieti un script care citeste numere pana cand suma lor depaseste 50

#!/bin/bash

sum=0

while [ $sum -lt 50 ]; do
	echo -n "Give number: "
	read num

	(( sum += num ))
done

echo $sum

