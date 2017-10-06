"""
For a given natural number n find the largest natural number written with the same digits
E.g. n=3658, m=8653.
"""

def determine(n):
	digitList = []
	while n:
		digitList.append(n % 10)
		n = int(n / 10)

	digitList.sort(reverse = True)
	print (digitList)
	
	result = 0
	for num in digitList:
		result = result * 10 + num

	return result

n = int(input("Input: "))
print (determine(n))


