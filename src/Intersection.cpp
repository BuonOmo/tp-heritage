/*************************************************************************
                                Intersection
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-- Réalisation de la classe <Intersection> (fichier Intersection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Intersection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Intersection::Contient (const Point & p) const
{
#ifdef MAP
    cout << "Appel à la méthode Contient de <Intersection>" << endl;
#endif
    bool premier (false); // si un premier objet contient le point on en
                          // cherche un second.
    for (Objet * obj : objets )
    {
        if ( obj -> Contient(p) )
        {
            if (premier)
            {
                return true;
            }
            premier = true;
        }
    }
    return false;
} //----- Fin de Contient

string Intersection::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <Intersection>" << endl;
#endif
    string toReturn = "OI "+nom;
    for (Objet * o : objets)
    {
        toReturn+= " "+o -> GetNom();
    }
    toReturn+="\r\n";
    toReturn+=to_string(objets.size());
    // nombre de lignes suivantes occupées par l’intersection en question

    for (Objet * o : objets)
    {
        toReturn+="\r\n"+o -> ToString();
    }
    return toReturn;
} //----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Intersection::Intersection ( const Intersection & unIntersection )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Intersection>" << endl;
#endif
} //----- Fin de Intersection (constructeur de copie)


Intersection::Intersection ( const string & unNom ,
                             const std::vector<Objet *> & desObjets)
    : ObjetComplexe(unNom, desObjets)
{
#ifdef MAP
    cout << "Appel au constructeur de <Intersection>" << endl;
#endif
} //----- Fin de Intersection


Intersection::~Intersection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Intersection>" << endl;
#endif
} //----- Fin de ~Intersection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
