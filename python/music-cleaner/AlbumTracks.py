#! /usr/bin/python

import musicbrainz2.webservice as ws
import musicbrainz2.model as m

import sys
#Pass in an artist object and an album to search for
#returns the releaseID
def getReleaseID(searchArtist,searchAlbum):
	#get the artist onject
	q = ws.Query()
	f = ws.ArtistFilter(searchArtist,5)
	artist = q.getArtists(f)[0].artist

	#search the Album's
	inc = ws.ArtistIncludes(releases=(m.Release.TYPE_OFFICIAL, m.Release.TYPE_ALBUM), tags=True, releaseGroups=True)
	artist = q.getArtistById(artist.id,inc)
	for release in artist.getReleases():	   
		if release.title.lower() == searchAlbum.lower():
			return release.id
	
	#Search the EP's
	inc = ws.ArtistIncludes( releases=(m.Release.TYPE_OFFICIAL, m.Release.TYPE_EP), tags=True, releaseGroups=True)
	artist = q.getArtistById(artist.id, inc)
	for release in artist.getReleases():	   
		if release.title.lower() == searchAlbum.lower():
			return release.id

def getRelease(releaseID):
	q = ws.Query()

	inc = ws.ReleaseIncludes(artist=True, releaseEvents=True, labels=True, discs=True, tracks=True, releaseGroup=True)
	release = q.getReleaseById(releaseID, inc)
	return release




	
