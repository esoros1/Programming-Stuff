import time

start = time.time()

def hasSameNumber(num,check):
	num = str(num)
	check = str(check)
	
	for i in check:
		if i not in num: return False
	return True

i = 2
found = False
while not found:
	if hasSameNumber(i,i*2) and hasSameNumber(i,i*3) and hasSameNumber(i,i*4) and hasSameNumber(i,i*5) and hasSameNumber(i,i*6):
		print i,i*2,i*3,i*4,i*5,i*6
		found = True
	else:
		i += 1

print "found in %f seconds" % float(time.time()-start)
