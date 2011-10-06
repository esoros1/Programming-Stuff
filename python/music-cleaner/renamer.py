#! /usr/bin/python

from AlbumTracks import getRelease, getReleaseID
from AlbumArt import downloadArtToPath
import mutagen
import os
#do all of the mp3s start with numbers?
def isNumeric(mp3s):
	for i in range(len(mp3s)):
		mp3 = mp3s[i]
		if int(mp3[:2]) != i+1:
			return False
	return True


path = r'/Users/ericsoros/documents/python/music-cleaner/Recipe for hate/'
mp3s = [ f for f in os.listdir(path) if os.path.isfile(os.path.join(path,f)) and f[-3:] == 'mp3']
release = getRelease(getReleaseID("Bad Religion","Recipe for Hate"))

for mp3 in mp3s:
	tag = mutagen.File(os.path.join(path,mp3), easy = True)
	tag.delete()

for i in range(len(mp3s)):
	mp3 = mp3s[i]
	tag = mutagen.File(os.path.join(path,mp3),easy = True)

	tag['album'] = release.title
	tag['artist'] = release.artist.name
	tag['title'] = release.tracks[i].title
	tag['performer'] = release.artist.name
	tag['tracknumber'] = '{0}/{1}'.format(str(i+1),str(len(mp3s)))

	tag.save()

downloadArtToPath("Bad Religion","Recipe for Hate",path)


#if len(sys.argv) < 2:
#	print "Useage: Artist - Album"
#	sys.exit(1)


#parse the command line argument
#searchArtist = ""
#searchAlbum = ""
#args = ""
#for arg in sys.argv[1:]:
#	args += arg+" "
#strip whitespace
#argsSplit =  args.split("-")
#searchArtist = argsSplit[0].strip()
#searchAlbum = argsSplit[1].strip()

#for track in getReleaseTracks(getReleaseID(searchArtist,searchAlbum)):
#	print track.title


