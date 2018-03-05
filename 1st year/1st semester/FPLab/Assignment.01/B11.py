"""
The palindrome of a number is the number obtained by reversing the order of digits. E.g.
palindrome (237) = 732). For a given natural number n, determine its palindrome
"""

def determinePalindrome(n):
	pal = 0
	while n:
		pal = pal * 10 + n % 10
		n = int(n / 10)

	return pal

n = int(input("Input: "))
print (determinePalindrome(n))