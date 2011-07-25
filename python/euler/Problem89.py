#PROJECT EULER 89: ROMAN NUMERALS



# 1 dict for mapping numerals to values, and another to go the otherway
# not exactly beautiful, but whatever
numerals = {}
numerals["I"] = 1
numerals["IV"] = 4
numerals["V"] = 5
numerals["IX"] = 9
numerals["X"] = 10
numerals["XL"] = 40
numerals["L"] = 50
numerals["XC"] = 90
numerals["C"] = 100
numerals["CD"] = 400
numerals["D"] = 500
numerals["CM"] = 900
numerals["M"] = 1000

values = {}
values[1] = "I"
values[4] = "IV"
values[5] = "V"
values[9] = "IX"
values[10] = "X"
values[40] = "XL"
values[50] = "L"
values[90] = "XC"
values[100] = "C"
values[400] = "CD"
values[500] = "D"
values[900] = "CM"
values[1000] = "M"

#sum valid roman numeral, where s is a valid string representation
#of a roman numeral
def sumRomanNumeral(s):
	result = 0
	i = 0
	while i < len(s):
		#if the last one, than just add the value
		if i == len(s) - 1:
			result += numerals[s[i]]
			i += 1
		#else, check to see if the next two are valid
		else:
			if s[i:i+2] in numerals:
				result += numerals[s[i:i+2]]
				i += 2
			#if the next two are not valid, than just add the on
			else:
				result += numerals[s[i]]
				i += 1
	return result

#give the valid roman numeral representation of n with the least amount of characters
def lowestRomanNumeral(n):
	result = ""
	while n > 0:
		for key in sorted(values,reverse = True):
			if n >= key:
				n -= key
				result += values[key]
				break
	return result

result = 0
f = open("roman.txt","r")
for line in f:
	#strip whitespace
	s = line.rstrip()
	lowest = lowestRomanNumeral(sumRomanNumeral(s))
	result += len(s) - len(lowest)
print result
				
