"""
Consider a given natural number n. Determine the product p of all the proper factors of n
"""

from math import sqrt

# determines the product of all the proper factors of n
def productOfProperFactors(n):
	# product
	p = 1

	for d in range(2, int(sqrt(n) + 1)):
		if n %  d == 0:
			p = p * d

			if int(n / d) != d:
				p = p * int(n / d)

	return p
			
n = int(input("Input: "))
print(productOfProperFactors(n))
