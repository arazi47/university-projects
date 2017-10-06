"""
Generate the first prime number larger than a given natural number n
"""

from math import sqrt

def prime(n):
	if n < 2:
		return False
	if n % 2 == 0 and n != 2:
		return False

	for d in range (3, int(sqrt(n) + 1), 2):
		if n % d == 0:
			return False

	return True

def generate(n):
	n = n + 1 # the number we're looking for is larger than the given one
	if n % 2 == 0 and n != 2: # and n != 2 => don't skip number 2
		n = n + 1

	while not prime(n):
		n = n + 2

	return n

n = int(input("Input: "))
print (generate(n))
