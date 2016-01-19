/*************************************************************************
                                Polygone
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Interface de la classe <Polygone> (fichier Polygone) ----
#ifndef POLYGONE_H
#define POLYGONE_H

//--------------------------------------------------- Interfaces utilisées
#include "ObjetSimple.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Polygone>
//
//
//------------------------------------------------------------------------

class Polygone : public ObjetSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contient (Point p) const;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Polygone ( const Polygone & unPolygone );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polygone ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Polygone ( );
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

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Polygone>

#endif // POLYGONE_H
