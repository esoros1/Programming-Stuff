def sumNum(num):
	result = 0
	num = str(num)
	for i in num:
		result += int(i)
	return result

result = 0
for a in range(1,101):
	for b in range(1,101):
		temp = sumNum(a**b)
		if temp > result:
			result = temp
print result
