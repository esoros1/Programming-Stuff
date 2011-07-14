import math
import time

MAX = 1000000

start = time.time()
def isPrime(num):
	for i in range(2,int(math.sqrt(num)+1)):
		if num%i == 0: return False
	return True
primes = set()

for i in range(2,MAX):
	if isPrime(i): primes.add(i)


#is is trucatable from left to right?
#pass in the numbers and the set of primes
def LtoR(num,primes):
	for i in range(0,len(num)):
		if int(num[i:]) not in primes: return False
	return True

def RtoL(num,primes):
	for i in range(0,len(num)):
		if int(num[0:len(num)-i]) not in primes: return False
	return True

result = []
for i in primes:
	num = str(i)
	if LtoR(num,primes) and RtoL(num,primes):
		result.append(i)
print sum(result)
print "Found in %f seconds" %float(time.time()-start)
