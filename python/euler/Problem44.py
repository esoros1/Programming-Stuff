#add the first 1000pentagonal numbers to a set
nums = set()

for i in range(1,10000):
	nums.add(i*(3*i-1)/2)

for i in nums:
	for j in nums:
		if i+j in nums and abs(i-j) in nums:
			print abs(i-j)
