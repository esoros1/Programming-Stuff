import math

def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num%i == 0: return False
	return True

ratio = 1.0
done = False
num = 1
sideLength = 2
corner = 0
nums = []
numPrime = 0
while ratio > 0.10:
	while done == False and ratio > 0.10:
		num += sideLength
		nums.append(num)
		if isPrime(num): numPrime += 1
		corner += 1
		if corner == 4:
			done = True
			corner = 0
			ratio = float(numPrime) / float(len(nums))
			print ratio
	sideLength += 2
	done = False

print sideLength +1


