
#return the smallest permutation of the number
def smallestPermutation(n):
	return "".join(sorted(str(n)))
nums = {}

i = 2
found = False
while not found:
	numString = smallestPermutation(i**3)
	#dictionary of lists. HOW CLEVER!
	if numString not in nums:
		nums[numString] = []
		nums[numString].append(i)
	else:
		nums[numString].append(i)
	i += 1
	found = len(nums[numString]) == 5
#this is the largest, go through its permutations and find the smallest one that is cube
print nums[numString][0] ** 3
		

