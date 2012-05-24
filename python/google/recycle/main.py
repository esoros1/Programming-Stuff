#rotate a string
def rotate(str):
	return str[1:] + str[:1]

def no_leading_zero(str):
	return str[0] != '0'

def all_rotations(str):
	result = []	
	for i in range(len(str) - 1):
		str_rotate = rotate(str)
		if str_rotate != str:		
			result.append(str_rotate)
		str = rotate(str)
	return  set(filter(no_leading_zero,result))

def num_recycle(lower,upper):
	result = 0
	for i in range(lower,upper ):
		for num_str in filter( lambda x : int(x) < upper, all_rotations(str(i)) ):
			if i < int(num_str):
				result += 1
	return result

f = open('C-small-practice.txt', 'r')
out = open('out.txt','w')
cases = int(f.readline())
for i in range(cases):
	nums = f.readline().split(' ')
	out.write( 'Case #{0}: {1}\n'.format( str(i+1), num_recycle(int(nums[0].strip()), int(nums[1].strip()))) )

print num_recycle(1111,2222)
