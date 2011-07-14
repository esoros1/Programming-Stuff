#are the three digits pandigital
def isPan(x,y,z):
	# a dict that holds the number of times each value occurs
	nums = {}
	while x != 0:
		temp = x % 10
		#if it is in the dict, than it is a repeat. return false
		if temp == 0: return False
		if temp in nums:
			return False
		else:
			nums[temp] = 1
		x = x/10

	while y != 0:
		temp = y % 10
			#if it is in the dict, than it is a repeat. return false
		if temp == 0: return False
		if temp in nums:
			return False
		else:
			nums[temp] = 1
		y = y/10

	while z != 0:
		temp = z % 10
		if temp == 0: return False
		if temp in nums:
			return False
		else:
			nums[temp] = 1
		z= z/10

	#Are there nine digits?
	return len(nums) == 9
	

#sum all of the products
result = 0


s = ( (x,y,x*y) for x in range(2,4500) for y in range(x+1,4500) if isPan(x,y,x*y) )

nums = {}

for group in s:
	temp = group[2]
	if temp not in nums:
		print group
		nums[temp] = 1
		result += temp
	

print result

