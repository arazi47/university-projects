"""
For a given natural number n find the minimal natural number m formed with the same digits.
E.g. n=3658, m=3568
"""

def determine(n):
	digitList = []
	while n:
		digitList.append(n % 10)
		n = int(n / 10)

	digitList.sort()
	
	result = 0
	for num in digitList:
		result = result * 10 + num

	return result

n = int(input("Input: "))
print (determine(n))


