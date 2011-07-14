import math
MAX = 100

def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num%i == 0: return False
	return True

def findMax(i,primes,primesHash):
	result = 0
	runningTotal = 0
	numPrimes = 0
	primes = primes[i::]
	while runningTotal < MAX:
		print primes[i]
		runningTotal += primes[i]
		if runningTotal in primes:
			result = runningTotal
		i += 1
		numPrimes += 1
	return result


primesHash = set()
primes = []

for i in range(2,MAX):
	if isPrime(i): 
		primes.append(i)
		primesHash.add(i)

print findMax(1,primes,primesHash)

