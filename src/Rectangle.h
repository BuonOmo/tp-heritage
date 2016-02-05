/*************************************************************************
                                Rectangle
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ----
#ifndef RECTANGLE_H
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilisées
#include "ObjetSimple.h"
#include "Point.h"

//------------------------------------------------------------------------
// Classe permettant d’utiliser l’objet Rectangle :
// permet principalement de vérifier si un point est sur le rectangle et
// de deplacer le rectangle dans l’espace.
//------------------------------------------------------------------------

class Rectangle : public ObjetSimple
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
    Rectangle ( const Rectangle & unRectangle );
    // Contrat :
    // Constructeur de copie basé sur la surcharge d’operateur = de
    // ObjetSimple.

    Rectangle ( const string & nom = "" );
    // Mode d'emploi :
    // Constructeur par defaut, à utiliser avec la methode addPoint().
    // Contrat :
    // L’ajout de points ulterieure n’est pas vérifiée, c’est à la charge
    // de l’utilisateur d’en mettre deux. Il est recommandé d’instancier
    // un nom.

    Rectangle ( const string & unNom,
                const Point & p1,
                const Point & p2);
    // Contrat :
    // Constructeur prenant deux Points et appelant le constructeur
    // équivalent de ObjetSimple.

    virtual ~Rectangle ( );
    // Contrat :
    // Affiche les appels au destructeur de Rectangle.

};
#endif // RECTANGLE_H
