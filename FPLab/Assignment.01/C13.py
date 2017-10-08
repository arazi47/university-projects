"""
Determine the n-th element of the sequence 1,2,3,2,5,2,3,7,2,3,2,5,... obtained from the
sequence of natural numbers by replacing composed numbers with their prime divisors,
without memorizing the elements of the sequence
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

# @todo make this a little bit faster
def determineNthElement(n):
	# the value situated on 'counter' position
	element = 1

	# position of the element
	count = 1

	# natural number on which we actually operate on
	number = 1

	while count != n:
		# determine the prime divisors of n
		#if number % 2 == 0:
		#	number = number / 2
		#	count = count + 1
		#	element = 2

		#if count == n:
		#	return element
		print("Count " + str(count) + " - element " + str(element) + " - number " + str(number))

		# search for all possible divisors of n
		for d in range(2, int(number / 2 + 1), 1):
			if number % d == 0 and prime(d):
				count = count + 1
				element = d

				if count == n:
					return element

		if prime(number):
			count = count + 1
			element = number

		if count == n:
			return element

		number = number + 1

	# if n == 1
	return element

n = int(input("Input: "))
print(determineNthElement(n))