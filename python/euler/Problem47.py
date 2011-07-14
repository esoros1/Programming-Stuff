import math


def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num%i == 0: return False
	return True

def hasUniqueDigits(lst):
	lst = sorted(lst)
	for i in range(0,len(lst)-1):
		if lst[i] == lst[i+1]:
			return False
	return True

#return the smallest prime factor 
def smallestPrimeFactor(num,primes):
	for i in primes:
		if num % i == 0:
			return i
#return a list of prime factors
def getPrimeFactors(num,primes):
	result = []
	while(num != 1):
		repeat = False
		factor = smallestPrimeFactor(num,primes)
		#check to see if it is in factor
		for i in range(0,len(result)):
			if result[i] == factor:
				result[i] = result[i] * factor
				repeat = True	
		if not repeat:
			result.append(factor)	
		num = num/factor
	return result

primes = [ x for x in xrange(2,1000000) if isPrime(x) ]



i = 4
found = False
while not found:
	print i,i+1,i+2,i+3
	lst1 = getPrimeFactors(i,primes)
	lst2 = getPrimeFactors(i+1,primes)
	lst3 = getPrimeFactors(i+2,primes)
	lst4 = getPrimeFactors(i+3,primes)

	if len(lst1) == 4 and len(lst2) == 4 and len(lst3) == 4 and len(lst4) == 4:
		found = hasUniqueDigits(lst1+lst2+lst3+lst4)

	if not found:
		i += 1
print i


			

