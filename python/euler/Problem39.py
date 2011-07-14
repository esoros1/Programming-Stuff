def getNumSolutions(p):
	p = p /2
	return len([(a,b,c) for a in range(1,p) for b in range(a+1,p) for c in range(b+1,p) if a+b+c == p and a*a + b*b == c*c)])

result = -1
largest = 0
for i in range(12,1001):
	print i
	temp = getNumSolutions(i)
	if temp > largest:
		largest = temp
		result = i

print result
	
