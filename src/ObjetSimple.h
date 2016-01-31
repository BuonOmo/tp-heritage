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
#include <vector>
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
    virtual bool Contient ( Point p ) const = 0;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    void Deplacer ( Point p );
    // Mode d'emploi :
    // Déplace l’objet selon le vecteur correspondant à p.
    //
    // Contrat :
    // -

    virtual string ToString () const = 0;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.

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

    ObjetSimple ( const vector<Point> & desPoints = *(new vector<Point>),
                  const string & description = "",
                  const string & nom = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    ObjetSimple ( const string & nom,
                  const string & description,
                  const Point & p1,
                  const Point & p2);

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
std::vector<Point> points;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//-------------------------------------- Types dépendants de <ObjetSimple>

#endif // OBJETSIMPLE_H
