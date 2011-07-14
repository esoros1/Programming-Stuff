import itertools
import time

t = time.time()
#is it divisible by the primes
def d(num):
	if int(num[1:4]) % 2 != 0: return False
	if int(num[2:5]) % 3 != 0: return False
	if int(num[3:6]) % 5 != 0: return False
	if int(num[4:7]) % 7 != 0: return False
	if int(num[5:8]) % 11 != 0: return False
	if int(num[6:9]) % 13 != 0: return False
	if int(num[7:10]) % 17 != 0: return False
	return True

s = itertools.permutations(['0','1','2','3','4','5','6','7','8','9'])

#go through the permutations, and find ones that fit the problem
result = 0
for num in s:
	num = "".join(num)
	if d(num):
		result += int(num)

print result
print "Found in %f seconds" %float(time.time()-t)	
