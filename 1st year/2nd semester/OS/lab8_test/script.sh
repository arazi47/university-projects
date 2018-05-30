# scrieti un script citeste de la tastatura zi, luna
# afiseaza nr de utilizatori distincti care s-au logat in data respectiva

echo -n "Day: "
read day

if [ $day -lt 1 ] || [ $day -gt 31 ]; then
	echo Bad day entered
	exit
fi

echo -n "Month: "
read month

last | sed '$d' | grep "tty2" | awk '{print $1, $5, $6}' | grep "$month $day" | sort | uniq | wc -l

