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
void ObjetSimple::Deplacer ( const Point & p )
{
    for (size_t i = 0; i < points.size(); ++i)
    {
        points[i] = points[i] + p;
        
    }
} //----- Fin de Deplacer

//------------------------------------------------- Surcharge d'opérateurs
ObjetSimple & ObjetSimple::operator = ( const ObjetSimple & unObjetSimple )
// Algorithme :
//
{
    if (this != &unObjetSimple)
    {
        points = unObjetSimple.points;
        nom = unObjetSimple.nom;
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
                           const string & nom )
    : Objet(nom), points (desPoints)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ObjetSimple

ObjetSimple::ObjetSimple ( const string & nom,
                           const Point & p1,
                           const Point & p2)
    : Objet(nom)
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
