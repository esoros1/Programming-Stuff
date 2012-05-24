def square(x):
	return x * x

#calculate a^b (mod n)
def mod_exp(a,b,n):
	if b == 0:
		return 1
	elif b % 2 == 0:
		return square(mod_exp(a,b/2,n)) % n
	else:
		return a * (mod_exp(a,b-1,n)) % n
		
print mod_exp(903,319,3737)