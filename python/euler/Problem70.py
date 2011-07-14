import math
import time
MAX = 10000000

#return the smallest prime factor 
def smallestPrimeFactor(num,primes):
	for i in primes:
		if num % i == 0:
			return i
	return num

#return a list of prime factors
def getPrimeFactors(num,primes):
	result = []
	while(num != 1):
		factor = smallestPrimeFactor(num,primes)
		#check to see if it is in factor
		if factor not in result:
			result.append(factor)	
		num = num/factor
	return result

def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num%i == 0: return False
	return True

def numRelativePrime(num,primes):
	factors = getPrimeFactors(num,primes)
	for i in factors:
		num *= (1.0 - (1.0/float(i)))
	return int(num)

#are two numbers permutations of each other?
def arePermutation(lhs,rhs):
	return sorted(str(lhs)) == sorted(str(rhs))

primes = [ x for x in range(2,int(math.sqrt(MAX)+1)) if isPrime(x) ]

start = time.time()
result = 10.0
answer = 0

for i in range(2,MAX):
	temp = numRelativePrime(i,primes)
	if arePermutation(i,temp):
		print i, temp, float(i) / float(temp)
		if float(i) / float(temp) < result:
			result = float(i) / float(temp)
			answer = i
			
print answer
print "Found in %f seconds" %float(time.time()-start)
		
