COMP     = g++
EDL      = g++
RM       = rm
RMFLAGS  = -f
OUTPUT   = -o
CPPFLAGS = -Wall # -DMAP
INTPATH  = ../src/
INT      = Objet.h ObjetComplexe.h ObjetSimple.h Point.h
INTPATH  =../src/
REAL     = $(REALPATH)$(INT:.h=.cpp)
REALPATH =../src/
OBJ      = $(OBJPATH)$(INT:.h=.o) main.o
OBJPATH  =
LIBPATH  = #-L
INCPATH  = #-I
LIBS     = #-lm

ECHO  = @echo
EXE   = exe
CLEAN = Clean
#.SILENT:
.PHONY: $(CLEAN)

$(EXE) : $(OBJ)
	$(EDL) $(OUTPUT) $(EXE) $(OBJ)

%.o : $(INTPATH)%.cpp
	$(ECHO) "compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

Point.o : $(INTPATH)Point.h
Objet.o : $(INTPATH)Objet.h
ObjetComplexe.o : $(INTPATH)ObjetComplexe.h $(INTPATH)Objet.h
ObjetSimple.o : $(INTPATH)ObjetSimple.h $(INTPATH)Objet.h $(INTPATH)Point.h


Clean :
	$(ECHO) "Nettoyage du repertoire..."
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) core
