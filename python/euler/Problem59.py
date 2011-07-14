#is it a printable character?
def isValid(num):
	if num == 32:
		return True
	if num >= 65 and num <= 90:
		return True
	if num >= 97 and num <= 122:
		return True
	return False

f = open("cipher1.txt")

data = f.read().split(",")
data[len(data)-1] = '73'
#first second and thid letters to XOR against
fst = []
snd = []
thd = []


i = 0
for numStr in data:
	if i == 0:
		fst.append(int(numStr))
	if i == 1:
		snd.append(int(numStr))
	if i == 2:
		thd.append(int(numStr))
	i = (i + 1) % 3

fstChar = ord('a')
sndChar = ord('a')
thdchar = ord('a')

found = False

	canWork = True
	i = 0
	while canWork and isValid(fstChar):
		num = fst[i]
		if not isValid(num^fstChar):
			canWork = False
		else: i += 1
