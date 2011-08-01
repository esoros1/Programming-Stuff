#!/usr/bin/python

# take the elements from a list and turn it into a string
def listToString(l):
	result = ""
	for item in l:
		result += item
	return result
#takes a string of elements to envoke, a hashmap of elements that combine, and a list of elements that are opposed
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
				if opposed[0] in elementList and opposed[1] in elementList:
					elementList = []
	#remove the ' characters from the list
	return str(elementList).replace("""'""","")

def main():
	f = open('test.txt','r')
	cases = int(f.readline())
	combine = {}

	line = f.readline()
	line = f.readline()
	print line.strip().split(" ")

if __name__ == "__main__":
	main()
