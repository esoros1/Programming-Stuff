import math

def isPermutation(rhs,lhs):
	if rhs == lhs: return False
	rhs = sorted(str(rhs))
	lhs = sorted(str(lhs))
	for i in range(0,len(rhs)):
		if rhs[i] != lhs[i]:
			return False
	return True


def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num % i == 0: return False
	return True

primes = []
hashPrimes = set()
for i in range(1000,10000):
	if isPrime(i):
		hashPrimes.add(i)
		primes.append(i)


for i in range(0,len(primes)-1):
		for j in range(i,len(primes)-1):
				if isPermutation(primes[i],primes[j]):
					if( (primes[j] - primes[i]) + primes[j] in hashPrimes):
						if( isPermutation((primes[j] - primes[i]) + primes[j], primes[i]) ):
							found = True
							print str(primes[i])+str(primes[j])+str((primes[j]-primes[i])+primes[j])
	
				


