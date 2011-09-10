#! /usr/bin/python

import musicbrainz2.webservice as ws
import musicbrainz2.model as m

import sys


#concatinate the agrument
searchArtist = ""
for arg in sys.argv[1:]:
	searchArtist += arg +" "
searchArtist = searchArtist.strip()


q = ws.Query()

f = ws.ArtistFilter(searchArtist,5)
artistResults = q.getArtists(f)


for i in range(len(artistResults)):
	artist = artistResults[i].artist
	print str(i+1)+": "+ artist.name

choice = int(input("Which Artist Do You Want? "))

artist = artistResults[choice-1].artist

inc = ws.ArtistIncludes( releases=(m.Release.TYPE_OFFICIAL, m.Release.TYPE_ALBUM), tags=True, releaseGroups=True)
#print the artist, with albums
artist = q.getArtistById(artist.id,inc)
for release in artist.getReleases():	   
	print
	print "Id        :", release.id
	print "Title     :", release.title
	print "ASIN      :", release.asin
	print "Text      :", release.textLanguage, '/', release.textScript
	print "Types     :", release.types
	
#print the artist, with EP's
inc = ws.ArtistIncludes( releases=(m.Release.TYPE_OFFICIAL, m.Release.TYPE_EP), tags=True, releaseGroups=True)
artist = q.getArtistById(artist.id, inc)
for release in artist.getReleases():	   
	print
	print "Id        :", release.id
	print "Title     :", release.title
	print "ASIN      :", release.asin
	print "Text      :", release.textLanguage, '/', release.textScript
	print "Types     :", release.types





	
