/*************************************************************************
                    ObjetSimple  -  Segments, rectangles et polygones
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//-------- Réalisation de la classe <ObjetSimple> (fichier ObjetSimple) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ObjetSimple.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void ObjetSimple::Deplacer ( Point p )
{
    for (Point i : points)
    {
        i = i + p;
    }
} //----- Fin de Deplacer

string ObjetSimple::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <ObjetSimple>" << endl;
#endif
    string toReturn = nom;
    for (Point p : points)
    {
        toReturn+=" "+p.ToString();
    }
    return toReturn;
} //----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs
ObjetSimple & ObjetSimple::operator = ( const ObjetSimple & unObjetSimple )
// Algorithme :
//
{
    if (this != &unObjetSimple)
    {
        points = unObjetSimple.points;
        nom = unObjetSimple.nom;
        description = unObjetSimple.description;
        // TODO gerer l’appel à l’operateur = de la classe mere
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ObjetSimple::ObjetSimple ( const ObjetSimple & unObjetSimple )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ObjetSimple>" << endl;
#endif
    *this = unObjetSimple;
} //----- Fin de ObjetSimple (constructeur de copie)


ObjetSimple::ObjetSimple ( const vector<Point> & desPoints,
                           const string & description,
                           const string & nom )
    : Objet(nom, description), points (desPoints)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ObjetSimple

ObjetSimple::ObjetSimple ( const string & nom,
                           const string & description,
                           const Point & p1,
                           const Point & p2)
    : Objet(nom, description)
// Algorithme :
//
{
    points.push_back(p1);
    points.push_back(p2);
#ifdef MAP
    cout << "Appel au constructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ObjetSimple

ObjetSimple::~ObjetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ~ObjetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
