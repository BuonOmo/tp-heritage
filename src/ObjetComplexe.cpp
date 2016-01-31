/*************************************************************************
                        ObjetComplexe  -  liste d’objets
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//---- Réalisation de la classe <ObjetComplexe> (fichier ObjetComplexe) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ObjetComplexe.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void ObjetComplexe::Deplacer ( Point p )
{
    for (Objet * i : objets)
    {
        i -> Deplacer(p);
    }
} //----- Fin de Deplacer

string ObjetComplexe::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <ObjetComplexe>" << endl;
#endif
    string toReturn = description;
    for (string str : sousDescriptions)
    {
        toReturn+="\n\t"+str;
    }
    return toReturn;
} //----- Fin de ToString


//------------------------------------------------- Surcharge d'opérateurs
ObjetComplexe & ObjetComplexe::operator = ( const ObjetComplexe & unObjetComplexe )
// Algorithme :
//
{
    if (this != &unObjetComplexe)
    {
        objets = unObjetComplexe.objets;
		sousDescriptions = unObjetComplexe.sousDescriptions;
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ObjetComplexe::ObjetComplexe ( const ObjetComplexe & unObjetComplexe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ObjetComplexe>" << endl;
#endif
    *this = unObjetComplexe;
} //----- Fin de ObjetComplexe (constructeur de copie)


ObjetComplexe::ObjetComplexe (  const string & unNom,
                                const string & uneDescription,
                                const vector<Objet *> &desObjets,
                                const vector<string> &desSousDescriptions )
    : Objet(unNom, uneDescription),
      objets (desObjets),
      sousDescriptions (desSousDescriptions)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ObjetComplexe>" << endl;
#endif
} //----- Fin de ObjetComplexe


ObjetComplexe::~ObjetComplexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ObjetComplexe>" << endl;
#endif
} //----- Fin de ~ObjetComplexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
