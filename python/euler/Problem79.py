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
	#find the digits that come after each number in the passcode
	passcode = line.strip()
	k = passcode[0]
	v = strToLst(passcode[1:])
	for num in v:
		if num not in order[k]:				
			order[k].append(num)
	k = passcode[1]
	v = passcode[2]
	if v not in order[k]:
		order[k].append(v)

#Sort the digits base on the number of digits that come after it. They will be in the right order!
for (x,y) in sorted(order.items(), key = lambda (x,y): len(y), reverse = True):
	print x,

