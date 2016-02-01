/*************************************************************************
                           Point  -  gestion de points (vecteurs)
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//------------ Réalisation de la classe <Point> (fichier Point) ----------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int Point::GetX ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode GetX de <Point>" << endl;
#endif
    return x;
} //----- Fin de GetX

int Point::GetY ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode GetY de <Point>" << endl;
#endif
    return y;
} //----- Fin de GetY

string Point::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <Point>" << endl;
#endif
    string s;
    s+= to_string(x);
    s+= ' ';
    s+= to_string(y);
    return s;
} //----- Fin de ToString

bool Point::XIn ( const Point & p1, const Point & p2 ) const
{
#ifdef MAP
    cout << "Appel à la méthode XIn de <Point>" << endl;
#endif

    if (p1.GetX() > p2.GetX())
    {
        return x >= p2.GetX() && x <= p1.GetX();
    }
    return x >= p1.GetX() && x <= p2.GetX();
} //----- Fin de XIn

bool Point::YIn ( const Point & p1, const Point & p2 ) const
{
#ifdef MAP
    cout << "Appel à la méthode YIn de <Point>" << endl;
#endif

    if (p1.GetY() > p2.GetY())
    {
        return y >= p2.GetY() && y <= p1.GetY();
    }
    return y >= p1.GetY() && y <= p2.GetY();
} //----- Fin de YIn

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

ostream & operator << ( ostream & os, const Point & unPoint)
{
    os << "( " << unPoint.x << " : " << unPoint.y << " )";
    return os;
} //----- Fin de operator <<

Point & Point::operator + ( const Point &unPoint ) const
{
    return *(new Point( x + unPoint.x, y + unPoint.y));
} //----- Fin de operator +

Point & Point::operator - ( const Point &unPoint ) const
{
    return *(new Point( x - unPoint.x, y - unPoint.y));
} //----- Fin de operator -

int Point::operator * ( const Point &unPoint ) const
{
    return x*unPoint.x + y*unPoint.y;
} //----- Fin de operator *

int Point::operator ^ ( const Point &unPoint ) const
{
    return x*unPoint.y - y*unPoint.x;
} //----- Fin de operator ^

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
