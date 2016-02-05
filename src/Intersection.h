/*************************************************************************
                                Intersection
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//------ Interface de la classe <Intersection> (fichier Intersection.h) --
#ifndef INTERSECTION_H
#define INTERSECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "ObjetComplexe.h"
#include "Point.h"

//------------------------------------------------------------------------
// Permet de gerer une intersection d’objets.
//------------------------------------------------------------------------

class Intersection : public ObjetComplexe
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
    Intersection ( const Intersection & unIntersection );
    // Contrat :
    // Constructeur de copie basé sur la surcharge d’operateur = de
    // ObjetComplexe.

    Intersection ( const string & unNom,
                   const std::vector<Objet *> &desObjets);
   // Contrat :
   // Crée une intersection à partir d’une liste d’objets, en appelant le
   // constructeur idoine de ObjetComplexe.

    virtual ~Intersection ( );
    // Contrat :
    // Affiche les appels au destructeur de Intersection.

};

#endif // INTERSECTION_H
