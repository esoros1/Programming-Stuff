#is it a 1-9 pandigital with products 1..n???
def isPanMult(num):
	result = []
	i = 1
	while(len(result) != 9):
		temp = str(num * i)
		for c in temp:
			if c in result:
				return -1
			if c == '0':
				return -1
			result.append(c)
		i += 1
	return int("".join(result))

print max(isPanMult(x) for x in xrange(2,10000) if isPanMult(x) > 0)


