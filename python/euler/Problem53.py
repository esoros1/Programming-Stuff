import time

start = time.time()

#store the first 100 factorials
factorial = {}
factorial[1] = 1

for i in range(2,101):
	factorial[i] = factorial[i-1]*i

def choose(n,r):
	return factorial[n]/(factorial[r]*factorial[n-r])

result = 0
for n in range(2,101):
	for r in range(2,n):
		if choose(n,r) > 1000000:
			result += 1
print result
print "found in %f seconds" % float(time.time()-start)
