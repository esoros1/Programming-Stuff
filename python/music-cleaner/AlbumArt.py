#! /usr/bin/python

from BeautifulSoup import BeautifulSoup
import re
import urllib
import sys
path = r'/Users/ericsoros/documents/python/music-cleaner/'

def getSearchURL(artist, album):
	#add + betweem the words in the artists's and album's name
	formatted = (artist +" "+album).replace(' ','+')
	return r'http://www.albumart.org/index.php?srchkey={0}&itempage=1&newsearch=1&searchindex=Music'.format(formatted)

def getAlbumArts(artist, album):
	result = []

	site = urllib.urlopen(getSearchURL(artist,album))
	soup = BeautifulSoup(site)
	#find all of the album art download links
	for incident in soup.findAll('a', { 'title':'View larger image'}):
		result.append(incident.attrs[0][1])
	return result

#download the album art to the specified path
def downloadArtToPath(artist,album,path):
	urllib.urlretrieve(getAlbumArts(artist,album)[0],path+"folder.jpg")

def main():
	#parse the command line argument
	searchArtist = ""
	searchAlbum = ""
	args = ""
	for arg in sys.argv[1:]:
		args += arg+" "
	#strip whitespace
	argsSplit =  args.split("-")
	artist = argsSplit[0].strip()
	album = argsSplit[1].strip()

	print "Downloading Album Art"
	urllib.urlretrieve(getAlbumArts(artist,album)[0],path+"folder.jpg")

if __name__ == '__main__':
  main()
