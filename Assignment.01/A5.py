"""
Generate the largest prime number smaller than a given natural number n. If such a number
does not exist, a message should be displayed
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
	if n < 3:
		return -1

	n = n - 1; # the number we're looking for is smaller than the given one
	if n % 2 == 0 and n != 2:
		n = n - 1

	while not prime(n):
		n = n - 2

	return n

n = int(input("Input: "))
result = generate(n)
if result == -1:
	print("There is no smaller prime number than " + str(n) + ".")
else:
	print(result)
