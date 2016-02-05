#!/usr/bin/python2.7
#-*- coding: utf-8 -*-
import sys
import random

if(len(sys.argv) == 2):
	length = int(sys.argv[1])
	fichier = open("std.in", "w")
	nbRectangle = 0
	nbSegment = 0
	nbPolygone = 0
	nbUnion = 0
	nbIntersection = 0

	#Génération des données
	for i in range(1,length) :
		choice = random.randint(1,2)
		x1 = random.randint(-1000,1000)
		y1 = random.randint(-1000,1000)
		x2 = random.randint(-1000,1000)
		y2 = random.randint(-1000,1000)
		if(choice == 1):
			stringTest = "R rec" + str(nbRectangle) + " " + str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + "\n"
			nbRectangle = nbRectangle + 1
		else:
			stringTest = "S seg" + str(nbSegment) + " " + str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + "\n"
			nbSegment = nbSegment + 1
		fichier.write(stringTest)
	#Génération de polygones
	for i in range(1,length/10):
		stringTest = "PC pol" + str(nbPolygone)
		for i in range(1,random.randint(4,7)):
			x = random.randint(-1000,1000)
			y = random.randint(-1000,1000)
			stringTest += " " + str(x) + " " + str(y)
		stringTest += "\n"
		nbPolygone = nbPolygone + 1
		fichier.write(stringTest)
	#Génération d'ensembles
	for i in range(1,length/10):
		choice = random.randint(1,2)
		if(choice == 1):
			stringTest = "OR union" + str(nbUnion) + " rec" + str(random.randint(1,nbRectangle)-1) + " seg" + str(random.randint(1,nbSegment)-1) + " rec" + str(random.randint(1,nbRectangle)-1) + " seg" + str(random.randint(1,nbSegment)-1) + "\n"
			nbUnion = nbUnion + 1
		else:
			stringTest = "OI intersection" + str(nbIntersection) + " rec" + str(random.randint(1,nbRectangle)-1) + " seg" + str(random.randint(1,nbSegment)-1) + " rec" + str(random.randint(1,nbRectangle)-1) + " seg" + str(random.randint(1,nbSegment)-1) + "\n"
			nbIntersection = nbIntersection + 1
		fichier.write(stringTest)
	#Génération de tests d'appartenance
	for i in range(1,length/10):
		x1 = random.randint(-1000,1000)
		y1 = random.randint(-1000,1000)
		stringTest ="HIT " + "rec" + str(random.randint(1,nbRectangle)-1) + " " + str(x1) + " " + str(y1) + "\n"
		stringTest +="HIT " + "seg" + str(random.randint(1,nbSegment)-1) + " " + str(x1) + " " + str(y1) + "\n"
		stringTest +="HIT " + "union" + str(random.randint(1,nbUnion)-1) + " " + str(x1) + " " + str(y1) + "\n"
		stringTest +="HIT " + "intersection" + str(random.randint(1,nbIntersection)-1) + " " + str(x1) + " " + str(y1) + "\n"
		fichier.write(stringTest)
	#Génération de déplacements
	for i in range(1,length/10):
		x1 = random.randint(-1000,1000)
		y1 = random.randint(-1000,1000)
		stringTest ="MOVE " + "rec" + str(random.randint(1,nbRectangle)-1) + " " + str(x1) + " " + str(y1) + "\n"
		stringTest +="MOVE " + "seg" + str(random.randint(1,nbSegment)-1) + " " + str(x1) + " " + str(y1) + "\n"
		stringTest +="MOVE " + "union" + str(random.randint(1,nbUnion)-1) + " " + str(x1) + " " + str(y1) + "\n"
		stringTest +="MOVE " + "intersection" + str(random.randint(1,nbIntersection)-1) + " " + str(x1) + " " + str(y1) + "\n"
		fichier.write(stringTest)
	fichier.write("EXIT\n")
	fichier.close()
else:
	print "erreur parametre"
