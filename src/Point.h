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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Point>
//
//
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

    bool XIn ( Point p1, Point p2 ) const;
    // Mode d’emploi :
    // Permet de voir si l’abscisse d’un point est comprise entre celles
    // de deux autres.
    // Contrat :
    // Vrai si inclu.

    bool YIn ( Point p1, Point p2 ) const;
    // Mode d’emploi :
    // Permet de voir si l’abscisse d’un point est comprise entre celles
    // de deux autres.
    // Contrat :
    // Vrai si inclu.

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & unPoint );

    friend std::ostream & operator << ( std::ostream & os, const Point & unPoint);
    // Contrat :
    // Affiche ( x : y )

    Point & operator + ( const Point & unPoint ) const;
    // Contrat :
    // Ajoute les x et les y separement et renvoi le résultat

    Point & operator - ( const Point & unPoint ) const;
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
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point ( int aX = 0, int aY = 0 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
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
    int x;
    int y;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
