import time
MAX = 100000

t = time.time()

pent = set((n*(3*n-1)/2) for n in range(1,MAX))
hexa = set((n*(2*n-1)) for n in range(1,MAX))

found = False
i = 286
while not found and i < MAX:
	triangle = (i*(i+1))/2
	if triangle in pent and triangle in hexa:
		print triangle
		found = True	
	i = i +1
print "Found in %f/Seconds" %   float(time.time()-t)
