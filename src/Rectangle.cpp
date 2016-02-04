/*************************************************************************
                                Rectangle
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

bool Rectangle::Contient ( const Point & p ) const
{
#ifdef MAP
    cout << "Appel à la méthode Contient de <Rectangle>" << endl;
#endif
    return p.XIn(points.back(), points.front())
           &&
           p.YIn(points.back(), points.front());
} //----- Fin de Contient

Objet * Rectangle::Copier ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode Copier de <Rectangle>" << endl;
#endif
    return new Rectangle(*this);
} //----- Fin de Copier

string Rectangle::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <Rectangle>" << endl;
#endif
    string toReturn = "R "+nom /*+ " 2"*/;
    for (Point p : points)
    {
        toReturn+=" "+p.ToString();
    }
    return toReturn;
} //----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle )
    : ObjetSimple(unRectangle)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)

Rectangle::Rectangle ( const string & nom ) : ObjetSimple(nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "#Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::Rectangle ( const string & unNom,
                       const Point & p1,
                       const Point & p2)
    : ObjetSimple( unNom, p1, p2 )
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
