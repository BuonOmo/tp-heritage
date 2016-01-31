COMP     = g++
EDL      = g++
RM       = rm
RMFLAGS  = -f
OUTPUT   = -o
CPPFLAGS = -Wall -std=c++11 #-DMAP
INTPATH  = ../src/
INT      = Objet.h ObjetComplexe.h ObjetSimple.h Point.h Segment.h Polygone.h Rectangle.h Union.h Intersection.h Historique.h
INTPATH  =../src/
#REAL     = $(REALPATH)$(INT:.h=.cpp)
REALPATH =../src/
OBJ      = $(OBJPATH)$(INT:.h=.o) Main.o
OBJPATH  =
LIBPATH  = #-L
INCPATH  = #-I
LIBS     = #-lm

ECHO  = @echo
EXE   = Heritage
CLEAN = clean
#.SILENT:
.PHONY: $(CLEAN)

$(EXE) : $(OBJ)
	$(EDL) $(OUTPUT) $(EXE) $(OBJ)

%.o : $(INTPATH)%.cpp
	$(ECHO) "compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

Point.o : $(INTPATH)Point.h
Objet.o : $(INTPATH)Objet.h $(INTPATH)Point.h
ObjetComplexe.o : $(INTPATH)ObjetComplexe.h $(INTPATH)Objet.h
ObjetSimple.o : $(INTPATH)ObjetSimple.h $(INTPATH)Objet.h $(INTPATH)Point.h
Polygone.o : $(INTPATH)ObjetSimple.h $(INTPATH)Objet.h $(INTPATH)Point.h $(INTPATH)Polygone.h
Rectangle.o : $(INTPATH)ObjetSimple.h $(INTPATH)Objet.h $(INTPATH)Point.h $(INTPATH)Rectangle.h
Segment.o : $(INTPATH)ObjetSimple.h $(INTPATH)Objet.h $(INTPATH)Point.h $(INTPATH)Segment.h
Union.o : $(INTPATH)ObjetComplexe.h $(INTPATH)Objet.h $(INTPATH)Point.h $(INTPATH)Union.h
Intersection.o : $(INTPATH)ObjetComplexe.h $(INTPATH)Objet.h $(INTPATH)Point.h $(INTPATH)Intersection.h
Historique.o : $(INTPATH)Historique.h


clean :
	$(ECHO) "Nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core
