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
void ObjetSimple::Shift ( Point p )
{
    for (Point i : points)
    {
        i = i + p;
    }
} //----- Fin de Shift

/*
bool ObjetSimple::Contient (Point p) const
{
#ifdef MAP
    cout << "Appel à la méthode contient de <ObjetSimple>" << endl;
#endif
} //----- Fin de Contient
*/ //TODO supprimer ce bloc si =0 marche bien

//------------------------------------------------- Surcharge d'opérateurs
ObjetSimple & ObjetSimple::operator = ( const ObjetSimple & unObjetSimple )
// Algorithme :
//
{
    if (this != &unObjetSimple)
    {
        points = unObjetSimple.points;
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


ObjetSimple::ObjetSimple ( const list<Point> & desPoints,
                           const string & description,
                           const string & nom )
    : points (desPoints), Objet(nom, description)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ObjetSimple
/*
ObjetSimple::ObjetSimple ( )
{
#ifdef MAP
    cout << "Appel au constructeur par defaut de <ObjetSimple>" << endl;
#endif
}
*/
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
