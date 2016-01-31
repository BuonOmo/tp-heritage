/*************************************************************************
                                    Union
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Interface de la classe <Union> (fichier Union.h) --------
#ifndef UNION_H
#define UNION_H

//--------------------------------------------------- Interfaces utilisées
#include "ObjetComplexe.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Union>
//
//
//------------------------------------------------------------------------

class Union : public ObjetComplexe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contient (Point p) const;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    string ToString () const;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Union ( const Union & unUnion );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Union ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Union ( );
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

//-------------------------------------------- Types dépendants de <Union>

#endif // UNION_H
