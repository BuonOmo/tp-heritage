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

//------------------------------------------------------------------------
// Permet de gerer une union d’objets.
//------------------------------------------------------------------------

class Union : public ObjetComplexe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contient (const Point & p) const;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    Objet * Copier ( ) const;
    // Contrat :
    // Renvoi un pointeur vers une copie de l’objet.

    string ToString () const;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.


//-------------------------------------------- Constructeurs - destructeur
    Union ( const Union & unUnion );
    // Contrat :
    // Constructeur de copie basé sur la surcharge d’operateur = de
    // ObjetComplexe.

    Union ( const string & unNom,
            const std::vector<Objet *> &desObjets);
    // Contrat :
    // Crée une union à partir d’une liste d’objets, en appelant le
    // constructeur idoine de ObjetComplexe.

    virtual ~Union ( );
    // Contrat :
    // Affiche les appels au destructeur de Union.

};

#endif // UNION_H
