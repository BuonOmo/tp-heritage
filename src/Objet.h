/*************************************************************************
                                    Objet
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//---------------- Interface de la classe <Objet> (fichier Objet.h) ------
#ifndef OBJET_H
#define OBJET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Objet>
//
//
//------------------------------------------------------------------------

class Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void shift ( Point p );
    // Mode d'emploi :
    // Déplace l’objet selon le vecteur correspondant à p.
    //
    // Contrat :
    // -


//------------------------------------------------- Surcharge d'opérateurs
    Objet & operator = ( const Objet & unObjet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Objet ( const Objet & unObjet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Objet ( const string & aName = "null");
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Objet ( );
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
    int c;
    string name;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Objet>

#endif // OBJET_H
