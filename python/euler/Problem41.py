import math
import itertools
import time


def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num % i == 0: return False
	return True

t = time.time()

primePan = set()
n = 3
#iterate througg all of the choices, and find the max
while (n <= 10):
	s = itertools.permutations(range(1,n))
	nums = []
	for lst in s:
		result = []
		for num in lst:
			result.append(str(num))
		nums.append(int("".join(result)))

	for num in nums:
		if isPrime(num):
			primePan.add(num)
	n += 1
print max(primePan)
	
	
print "Found in %f seconds" %float(time.time()-t)		
