/*************************************************************************
                    ObjetSimple  -  Segments, rectangles et polygones
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//-------- Réalisation de la classe <ObjetSimple> (fichier ObjetSimple) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ObjetSimple.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type ObjetSimple::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ObjetSimple & ObjetSimple::operator = ( const ObjetSimple & unObjetSimple )
// Algorithme :
//
{
    if (this != &unObjetSimple)
    {
        points = unObjetSimple.points;
		nombrePoints = unObjetSimple.nombrePoints;
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


ObjetSimple::ObjetSimple ( const list<Point> & desPoints )
    : points (desPoints)
// Algorithme :
//
{
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
