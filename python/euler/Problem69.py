import math

MAX = 1000000

#return the smallest prime factor 
def smallestPrimeFactor(num,primes):
	for i in primes:
		if num % i == 0:
			return i

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

def numRelativePrime(num,factors):
	for i in factors:
		num *= (1.0 - (1.0/float(i)))
	return int(num)

primes = [ x for x in range(2,MAX) if isPrime(x) ]


result = 0.0
answer = 0
for i in range(1,MAX):
	temp = numRelativePrime(i,getPrimeFactors(i,primes))
	print i
	if float(i)/float(temp) > result:
		result = float(i)/float(temp)
		answer = i
print answer
