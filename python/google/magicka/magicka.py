#!/usr/bin/python

# take the elements from a list and turn it into a string
def listToString(l):
	result = ""
	for item in l:
		result += item
	return result
#takes a string of elements to envoke, a hashmap of elements that combine, and a hashmap of elements that are opposed
#returns a string
def magicka(envokeOrder,combine,opposed):
	elementList = []
	for element in envokeOrder:
		elementList.append(element)
		#it has to have two elements before we can check anything
		if len(elementList) > 1:
			# if they last to elements combine...
			lastTwo = listToString(elementList[-2:])
			if lastTwo in combine:
				elementList = elementList[:-2]
				elementList.append(combine[lastTwo])
			elif len(opposed) > 1:
				if element in opposed and opposed[element] in elementList:
					elementList = []
	#remove the ' characters from the list
	return str(elementList).replace("""'""","")

#parsing the input from the file. Hacked together. Really ugly
def main():
	f = open('B-large-practice.in','r')
	cases = int(f.readline())
	out = open('out.txt','w')

	for cas in range(cases):
		combine = {}
		opposed = {}
		line = f.readline()
		data =  line.strip().split(" ")
		i = 0
		for j in range(int(data[i])):
			i += 1
			combine[data[i][0] + data[i][1]] = data[i][-1]
			combine[data[i][1] + data[i][0]] = data[i][-1]
		i += 1
		for j in range(int(data[i])):
			i += 1
			opposed[data[i][0]] = data[i][1]
			opposed[data[i][1]] = data[i][0]
		i += 1
		envokeOrder =  data[i+1]

		out.write('Case #{0}: {1}\n'.format(cas+1,magicka(envokeOrder,combine,opposed)))
	out.close()
	

if __name__ == "__main__":
	main()
