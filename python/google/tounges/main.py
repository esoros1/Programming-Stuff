def translate_str(map, str):
	result = []
	for c in str:
		if c.isalpha():
			result.extend(map[c])
		else:
			result.append(c)
	return ''.join(result)


map = {'a': 'y' , 'o' : 'e' , 'z' : 'q'}

strings_before = ['ejp mysljylc kd kxveddknmc re jsicpdrysi',
		          'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
                  'de kr kd eoya kw aej tysr re ujdr lkgc jv']

strings_after = ['our language is impossible to understand',
                 'there are twenty six factorial possibilities',
                 'so it is okay if you want to just give up']

for i in range(len(strings_before)):
	str_before = strings_before[i]
	str_after = strings_after[i]

	for c in range(len(str_before)):
		if c not in map:		
			map[str_before[c]] = str_after[c]

#the mapping is a bijection, so we can add keys the other way as well
temp = {}
for k,v in map.iteritems():
	if v not in map:
		temp[v] = k

for key in temp:	
	map[key] = temp[key]


if len(map) > 26:	
	f = open('A-small-practice.in')
	out = open('out.txt','w')	
	cases = int(f.readline())
	for i in range(cases):
		out.write( 'Case #{0}: {1}'.format(str(i+1),translate_str(map,f.readline())) )
	




