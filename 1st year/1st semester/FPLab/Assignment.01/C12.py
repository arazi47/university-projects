"""
The numbers n1 and n2 have the property P if their writings in basis 10 have the same digits
(e.g. 2113 and 323121). Determine whether two given natural numbers have the property P
"""

def configure(n):
	result = 0
	while n:
		result |= 1 << n % 10
		n = int(n / 10)

	return result

def property(a, b):
	a = configure(a)
	b = configure(b)

	return a == b

a = int(input("Input a: "))
b = int(input("Input b: "))
print (property(a, b))