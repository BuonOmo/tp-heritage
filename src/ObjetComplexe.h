/*************************************************************************
                        ObjetComplexe  -  liste d’objets
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//------ Interface de la classe <ObjetComplexe> (fichier ObjetComplexe) --
#ifndef OBJETCOMPLEXE_H
#define OBJETCOMPLEXE_H

//--------------------------------------------------- Interfaces utilisées
#include "Objet.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ObjetComplexe>
//
//
//------------------------------------------------------------------------

class ObjetComplexe : public Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contient ( Point p ) const = 0;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    void Deplacer ( Point p );
    // Mode d'emploi :
    // p correspond à un vecteur de déplacement et non un point.
    //
    // Contrat :
    // Déplace l’objet selon le vecteur correspondant à p.

    virtual string ToString () const = 0;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.

//------------------------------------------------- Surcharge d'opérateurs
    ObjetComplexe & operator = ( const ObjetComplexe & unObjetComplexe );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ObjetComplexe ( const ObjetComplexe & unObjetComplexe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ObjetComplexe ( const string & unNom = "",
                    const string & uneDescription = "",
                    const std::vector<Objet *> &desObjets = *(new std::vector<Objet *>),
                    const std::vector<string> &aSousDescriptions = *(new std::vector<string>));
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ObjetComplexe ( );
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
    std::vector<Objet *> objets;
    std::vector<string> sousDescriptions;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//------------------------------------ Types dépendants de <ObjetComplexe>

#endif // OBJETCOMPLEXE_H
