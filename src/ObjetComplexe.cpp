/*************************************************************************
                        ObjetComplexe  -  liste d’objets
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//---- Réalisation de la classe <ObjetComplexe> (fichier ObjetComplexe) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ObjetComplexe.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type ObjetComplexe::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ObjetComplexe & ObjetComplexe::operator = ( const ObjetComplexe & unObjetComplexe )
// Algorithme :
//
{
    if (this != &unObjetComplexe)
    {
        objets = unObjetComplexe.objets;
		sous-descriptions = unObjetComplexe.sous-descriptions;
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


ObjetComplexe::ObjetComplexe ( const Objet &desObjets, const string &desSous-Descriptions )
    : objets (desObjets), sous-descriptions (desSous-Descriptions);
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
