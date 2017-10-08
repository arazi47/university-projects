"""
Determine the twin prime numbers p1 and p2 immediately larger than the given non-null
natural number n. Two prime numbers p and q are called twin if q-p = 2
"""

from math import sqrt

def prime(n):
	if n < 2:
		return False
	if n % 2 == 0 and n != 2:
		return False

	for d in range(3, int(sqrt(n) + 1), 2):
		if n % d == 0:
			return False

	return True

# determines the twin primes p1 and p2 larger than the given non-null natural number n
def determineTwinPrimes(n):
	p1 = n + 1

	if p1 % 2 == 0:
		p1 = p1 + 1

	p2 = p1 + 2

	while not prime(p1) or not prime(p2):
		p1 = p1 + 2
		p2 = p2 + 2

	print("Found twin primes: " + str(p1) + " and " + str(p2) + ".")
	

n = int(input("Input: "))
determineTwinPrimes(n)