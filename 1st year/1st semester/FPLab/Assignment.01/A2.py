"""
Given the natural number n, determine the prime numbers p1 and p2 such that n = p1 + p2
(check the Goldbach hypothesis)
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

def printP1P2(n):
	if n < 2:
		print("The number must be >= 4!")
		return

	# in case the first prime number is 2
	if prime(n - 2):
		print("p1 = 2; p2 = " + str(n - 2) + ".")
		return

	for d in range(3, int(n), 2):
		if prime(d) and prime(n - d):
			print("p1 = " + str(d) + "; p2 = " + str(n - d) + ".")
			break

n = int(input("Input: "))
printP1P2(n)
