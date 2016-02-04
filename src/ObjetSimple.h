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
    virtual bool Contient ( const Point & p ) const = 0;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    void Deplacer ( const Point & p );
    // Mode d'emploi :
    // Déplace l’objet selon le vecteur correspondant à p.
    //
    // Contrat :
    // -

    void AddPoint (const Point & p);
    // Mode d'emploi :
    // Ajoute le point à l'objet.
    //
    // Contrat :
    // -
/*
    virtual string ToString () const = 0;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.
*/ //TODO supprimer ce bloc si il ne cause pas de bug

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

    ObjetSimple ( const string & nom );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ObjetSimple ( const vector<Point> & desPoints = *(new vector<Point>),
                  const string & nom = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    ObjetSimple ( const string & nom,
                  const Point & p1,
                  const Point & p2);
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
std::vector<Point> points;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//-------------------------------------- Types dépendants de <ObjetSimple>

#endif // OBJETSIMPLE_H
