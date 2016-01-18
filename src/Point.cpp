/*************************************************************************
                           Point  -  gestion de points (vecteurs)
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//------------ Réalisation de la classe <Point> (fichier Point) ----------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & aPoint )
{
    if (this != &aPoint)
    {
        x = aPoint.x;
		y = aPoint.y;
    }
    return *this;
} //----- Fin de operator =

Point & Point::operator + ( const Point &unPoint )
{
    return *(new Point( x + unPoint.x, y + unPoint.y));
} //----- Fin de operator +

int Point::operator * ( const Point &unPoint )
{
    return x*unPoint.x + y*unPoint.y;
}
//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & aPoint )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
    *this = aPoint;
} //----- Fin de Point (constructeur de copie)


Point::Point ( int aX, int aY )
    : x (aX), y (aY)
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
