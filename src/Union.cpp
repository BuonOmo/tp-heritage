/*************************************************************************
                                    Union
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Réalisation de la classe <Union> (fichier Union.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Union.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Union::Contient (const Point & p) const
{
#ifdef MAP
    cout << "Appel à la méthode Contient de <Union>" << endl;
#endif
    for (Objet * obj : objets )
    {
        if ( obj -> Contient(p) )
        {
            return true;
        }
    }
    return false;
} //----- Fin de Contient

Objet * Union::Copier ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode Copier de <Union>" << endl;
#endif
    return new Union (*this);
} //----- Fin de Copier

string Union::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <Union>" << endl;
#endif
    string toReturn = "OR "+nom;
    /*for (Objet * o : objets)
    {
        toReturn+= " "+o -> GetNom();
    }*/
    //toReturn+="\n";
    toReturn+=" " + to_string(objets.size());
    // nombre de lignes suivantes occupées par l’union en question
    for (Objet * o : objets)
    {
        toReturn+= " " + o -> ToString();
    }
    return toReturn;
} //----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Union::Union ( const Union & unUnion ) : ObjetComplexe(unUnion)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Union>" << endl;
#endif
} //----- Fin de Union (constructeur de copie)


Union::Union ( const string & unNom ,
               const std::vector<Objet *> & desObjets)
    : ObjetComplexe(unNom, desObjets)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Union>" << endl;
#endif
} //----- Fin de Union


Union::~Union ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Union>" << endl;
#endif
} //----- Fin de ~Union


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
