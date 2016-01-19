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


ObjetSimple::ObjetSimple ( const string & nom,
                           const string & description,
                           const list<Point> & desPoints )
    : points (desPoints), Objet(nom, description)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ObjetSimple

ObjetSimple::ObjetSimple ( const string &uneDescription )
    : Objet(uneDescription)
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
    string str (description);
    int pos(0);
    str = str.substr(str.find(" ")); // on enleve le type
    name = str.substr(0,str.find(" ")-1); // on selectionne le nom
    str = str.substr(str.find(" ")); // on enleve le nom
    int x,y;
    while (pos = str.find(" ") != str.npos)
    {
        x = stoi(str.substr(0, pos-1).c_str());
        str = str.substr(pos);
        pos = str.find(" ");
        pos = (pos == str.npos) ? str.size() : pos;
        y = stoi(str.substr(0, pos-1).c_str());
        if (str.size() > 0)
        {
            str = str.substr(pos);
        }
        // TODO revoir ce truc foireux
    }
} //----- Fin de ~ObjetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
