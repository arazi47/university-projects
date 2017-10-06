"""
Generate the largest perfect number smallest than a given natural number n. If such a number
does not exist, a message should be displayed. A number is perfect if it is equal to the sum of its
divisors, except itself. E.g. 6 is a perfect number (6=1+2+3)
"""

# determines wheter a given number is perfect or not
def isPerfectNumber(n):
	divSum = 1
	for d in range(2, int(n / 2) + 1):
		if n % d == 0:
			divSum = divSum + d

	return divSum == n

# determines the largest perfect number smaller than n
def determinePerfectNumber(n):
	n = n - 1
	while not isPerfectNumber(n):
		n = n - 1

	return n

n = int(input("Input: "))
print (determinePerfectNumber(n))
