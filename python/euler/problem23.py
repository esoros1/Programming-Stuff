import time
MAX = 28123

t = time.time()

def isAbundant(n):
	result = 0
	for i in range(1,(n/2)+1):
		if n % i == 0:
			result += i
	return result > n

abundants = set()
for i in range(11,MAX):
	if isAbundant(i): abundants.add(i)

sumAbundants = set()
for i in abundants:
	for j in abundants:
		sumAbundants.add(i+j)

print sum((x for x in range(MAX) if x not in sumAbundants))

print "Found in %f/Seconds" %   float(time.time()-t)








