/*************************************************************************
                                    Objet
                             -------------------
    d�but                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

///---------- R�alisation de la classe <Objet> (fichier Objet.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

///------------------------------------------------------ Include personnel
#include "Objet.h"

///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe

///----------------------------------------------------------- Types priv�s


///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- M�thodes publiques
// type Objet::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


///------------------------------------------------- Surcharge d'op�rateurs
Objet & Objet::operator = ( const Objet & unObjet )
// Algorithme :
//
{
} //----- Fin de operator =


///-------------------------------------------- Constructeurs - destructeur
Objet::Objet ( const Objet & unObjet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Objet>" << endl;
#endif
} //----- Fin de Objet (constructeur de copie)


Objet::Objet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Objet>" << endl;
#endif

} //----- Fin de Objet


Objet::~Objet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Objet>" << endl;
#endif
} //----- Fin de ~Objet


///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
