import re

#take in the regex, replace '()' with '[]'
def toRegEx(regEx):
	result = ""
	for c in regEx:
		if c == '(': result += '['
		elif c == ')': result += ']'
		else: result += c
	return result


f = open("A-large-practice.in",'r')
out = open("out.txt",'w')
#read in data from file
data = f.readline().split(" ")

l = int(data[0])
d = int(data[1])
n = int(data[2][:-1])

print l,d,n

words = []
for i in range(d):
	words.append(f.readline()[:-1])

for case in range(n):
	numFound = 0
	pattern = toRegEx(f.readline()[:-1])
	for word in words:
		match = re.search(pattern,word)
		if match: numFound += 1
	out.write("Case #{0}: {1}\n".format(case+1,numFound))
