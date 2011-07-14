def hasSameNum(n,m):
	n = str(n)
	m = str(m)
	for digit in n:
		if digit in m: return digit
#remove the first instance of the digit	
def remove(num,r):
	found = False
	num = str(num)
	r = str(r)
	result = []
	for digit in num:
		if digit == r and found == True or digit != r:
			result.append(digit)
		if digit == r and found == False:
			found = True
	return int(''.join(result))


fractions = [ (x,y) for x in range(10,100) if x % 10 != 0 for y in range(x+1,100) if y % 10 != 0 if hasSameNum(x,y) != None]



for group in fractions:
	i = group[0]
	j = group[1]
	r = hasSameNum(i,j)

	if float(i)/float(j) == float(remove(i,r)) / float(remove(j,r)):
		print group

