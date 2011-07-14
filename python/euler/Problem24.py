import itertools

s = itertools.permutations([0,1,2,3,4,5,6,7,8,9])

i = 0

ans = []
#find the 1,000,000 permutation, and turn it into a string
for per in s:
	i +=1
	if i == 1000000:
		result = per
		for j in per:
			ans.append(str(j))
		break

print "".join(ans)
