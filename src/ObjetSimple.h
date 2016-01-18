/*************************************************************************
                    ObjetSimple  -  Segments, rectangles et polygones
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//---------- Interface de la classe <ObjetSimple> (fichier ObjetSimple) --
#ifndef OBJETSIMPLE_H
#define OBJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Objet.h"
#include "Point.h"
#include <list>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ObjetSimple>
//
//
//------------------------------------------------------------------------

class ObjetSimple : public Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    ObjetSimple & operator = ( const ObjetSimple & unObjetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ObjetSimple ( const ObjetSimple & unObjetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ObjetSimple ( const std::list<Point> & desPoints );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ObjetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
std::list<Point> points;
int nombrePoints;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <ObjetSimple>

#endif // OBJETSIMPLE_H
