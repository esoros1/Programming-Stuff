import math
import time

start = time.time()

def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num%i == 0: return False
	return True
#can it be written as a sum of a prime and twice a square????
def primeSum(num,primes,sumOfSquares):
	for x in primes:
		if x > num : return False
		if (num-x)/2 in sumOfSquares: return True
	return False


primes = [x for x in range(10000) if isPrime(x)]

sumOfSquares = []
for i in range(1,1000):
	sumOfSquares.append(i*i)
	
oddComposites = (x  for x in range(10000) if not isPrime(x) and x % 2 != 0)

for num in oddComposites:
	if not primeSum(num,primes,sumOfSquares):
		print num
		break

print "Found in %f seconds" %float(time.time()-start)
