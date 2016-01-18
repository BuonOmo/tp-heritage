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
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & aPoint );

    Point & operator + ( const Point & unPoint );
    // Contrat :
    // ajoute les x et les y separement et renvoi le résultat

    int operator * ( const Point & unPoint);
    // Contrat :
    // Renvoi le produit scalaire de deux vecteurs.

    int operator ^ ( const Point & unPoint);
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
