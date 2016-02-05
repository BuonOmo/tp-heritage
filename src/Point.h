/*************************************************************************
                           Point  -  gestion de points (vecteurs)
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Interface de la classe <Point> (fichier Point) ----------
#ifndef POINT_H
#define POINT_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

//------------------------------------------------------------------------
// Permet de gerer des vecteurs : 2 entiers avec possibilité de faire un
// produit vectoriel, une addition, un produit scalaire, etc
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int GetX () const;
    // Contrat :
    // Renvoi la valeur de l'abscisse.

    int GetY () const;
    // Contrat :
    // Renvoi la valeur de l'ordonnée.

    string ToString () const;
    // Contrat :
    // Renvoi une chaine de caractère au format : "X Y"

    bool XIn ( const Point & p1, const Point & p2 ) const;
    // Mode d’emploi :
    // Permet de voir si l’abscisse d’un point est comprise entre celles
    // de deux autres.
    // Contrat :
    // Vrai si inclu.

    bool YIn ( const Point & p1, const Point & p2 ) const;
    // Mode d’emploi :
    // Permet de voir si l’abscisse d’un point est comprise entre celles
    // de deux autres.
    // Contrat :
    // Vrai si inclu.

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & unPoint );
    // Contrat :
    // Copie les deux entiers en utilisant les constructeurs de copie
    // d’entier par defaut.

    friend std::ostream & operator << ( std::ostream & os, const Point & unPoint);
    // Contrat :
    // Affiche ( x : y )

    Point operator + ( const Point & unPoint ) const;
    // Contrat :
    // Ajoute les x et les y separement et renvoi le résultat

    Point operator - ( const Point & unPoint ) const;
    // Contrat :
    // Effectue les soustractions des x et des y separement et renvoi le
    // résultat

    int operator * ( const Point & unPoint) const;
    // Contrat :
    // Renvoi le produit scalaire de deux vecteurs.

    int operator ^ ( const Point & unPoint) const;
    // Contrat :
    // Renvoi le produit vectoriel de deux vecteurs coplanaires.

//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & aPoint );
    // Contrat :
    // Constructeur de copie utilisant la surcharge de l’operateur =.

    Point ( int aX = 0, int aY = 0 );
    // Contrat :
    // aX définira l’abscisse, et aY l’ordonnée.

    virtual ~Point ( );
    // Contrat :
    // Affiche les appels au destructeur de Point.

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    int x;
    int y;

};

#endif // POINT_H
