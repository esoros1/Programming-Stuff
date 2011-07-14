def sumNum(n):
	result = 0
	while n > 0:
		result += n % 10
		n = n /10
	return result

#is num base to a power?
def isPower(num,base):
	if base == 1: return False
	p = 1
	while base ** p <= num:
		if base ** p == num:
			return True
		p += 1
	return False

result = []
for base in range(2,200):
	for p in range(2,20):
		num = base ** p
		if base == sumNum(num):
			result.append(num)

print sorted(result)[29]
