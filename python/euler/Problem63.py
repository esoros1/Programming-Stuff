def isNPower(num,power):
	i = 2
	while i**power <= num:	
		if i**power == num: 
			return True
			print i
		i += 1
	return False

s =  ( x**y for x in range(1,10) for y in range(x+1,70) if isNPower((x**y),(len(str(x**y))) ) )

result = 0

for num in s:
	result += 1

print result
	
