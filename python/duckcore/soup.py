from BeautifulSoup import BeautifulSoup
import re
import urllib

#class for a single post
#Album, Artist, Year, etc......
class Post:
	def __init__(self,post):
		# s is a string which contains Artist - Album/song (year)
		#parse the string
		s = str(post.find('a', { 'href' : re.compile(r'^h') }).string)

		#I hate regular expressions
		self.artist = "ARTIST ERROR"
		self.album = "ALBUM ERROR"
		self.date = "DATE ERROR"

		match = re.search(r'(.+)-(.+)\s\(?([\w\d-]+)\)?',s)
		if match:
			self.artist =  match.group(1).strip() 
			self.album = match.group(2).strip() 
			self.date = match.group(3).strip() 

#read in the site, and send it into the html parser
site = urllib.urlopen(r'http://www.duckcore.blogspot.com')
out = open("out.txt",'w')
soup = BeautifulSoup(site)
print "DONE FETCHING SITE"


#a list containing the posts on the frontpage
posts = []

#fill posts
for incident in soup.findAll('div', { 'class':'post-outer'}):
	posts.append(incident.contents[1])

print posts[1]







	
