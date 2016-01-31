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
void ObjetComplexe::Deplacer ( const Point & p )
{
    for (Objet * i : objets)
    {
        i -> Deplacer(p);
    }
} //----- Fin de Deplacer


//------------------------------------------------- Surcharge d'opérateurs
ObjetComplexe & ObjetComplexe::operator = ( const ObjetComplexe & unObjetComplexe )
// Algorithme :
//
{
    if (this != &unObjetComplexe)
    {
        objets = unObjetComplexe.objets;
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
                                const vector<Objet *> &desObjets )
    : Objet(unNom), objets (desObjets)
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
