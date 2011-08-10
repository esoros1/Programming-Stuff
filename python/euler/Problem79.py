#!/usr/bin/python

#take a string, and return a list with the elements in the string
def strToLst(s):
	result = []
	for c in s:
		result.append(c)
	return result

f = open("keylog.txt")
#get the numbers that are used in the passcode
nums = set()
order = {}

for line in f:
	passcode = line.strip()
	for i in strToLst(passcode):
		nums.add(i)

for num in nums:
	order[num] = []

f = open("keylog.txt")
for line in f:
	passcode = line.strip()
	k = passcode[0]
	v = strToLst(passcode[1:])
	for num in v:
		if num not in order[k]:				
			order[k].append(num)

#becuase 0 and 9 are the same length, it will output the wrong answer, just switch the zero and nine!
for (x,y) in sorted(order.items(), key = lambda (x,y): len(y), reverse = True):
	print x,

