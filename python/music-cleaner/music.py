#! /usr/bin/python

import os
import shutil

path = os.path.join(os.path.expanduser('~'),"music")
path = os.path.join(path,"music")

#path = os.path.join(path,"music")

audioExtensions = ["mp3","m4a","wma"]

def printDir(path):
	for item in os.listdir(path):
		print item

#does the folder or one of it's subdirectories contain an mp3?		
def hasMusic(path):
	folders = [ f for f in os.listdir(path) if os.path.isdir(os.path.join(path,f)) ]
	files = [ f for f in os.listdir(path) if os.path.isfile(os.path.join(path,f)) ]

	for f in files:
		if f[-3:] in audioExtensions:
			return True
	#check the subdirectories
	for f in folders:
		if hasMusic(os.path.join(path,f)):
			return True
	return False
	

folders = [ f for f in os.listdir(path) if os.path.isdir(os.path.join(path,f)) ]
for f in folders:
	newPath = os.path.join(path,f)
	if not hasMusic(newPath):
		shutil.rmtree(newPath)

	
		




