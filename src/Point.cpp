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
// type Point::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & aPoint )
// Algorithme :
//
{
    if (this != &aPoint)
    {
        X = aPoint.X;
			Y = aPoint.Y;
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & aPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
    *this = aPoint;
} //----- Fin de Point (constructeur de copie)


Point::Point ( int aX, int aY )
    : X (aX), Y (aY)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
