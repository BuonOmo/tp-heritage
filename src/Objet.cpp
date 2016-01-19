/*************************************************************************
                                    Objet
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//------------ Réalisation de la classe <Objet> (fichier Objet.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Objet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Objet::Shift ( Point p )
{
#ifdef MAP
    cout << "Appel à la méthode contient de <ObjetSimple>" << endl;
#endif
} //----- Fin de Shift

bool Objet::Contient (Point p) const
{
#ifdef MAP
    cout << "Appel à la méthode contient de <Objet>" << endl;
#endif
} //----- Fin de Contient
 //TODO supprimer ce bloc si =0 marche bien

string Objet::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <Objet>" << endl;
#endif
    return description;
} //----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs
Objet & Objet::operator = ( const Objet & unObjet )
// Algorithme :
//
{
    if (this != &unObjet)
    {
        nom = unObjet.nom;
        description = unObjet.description;
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Objet::Objet ( const Objet & unObjet )
// Algorithme :
//
{
    c++;
#ifdef MAP
    cout << "#Appel au constructeur de copie de <Objet>" << endl;
    cout << "#Nombre de réferences : " << c << endl << endl;
#endif
    *this = unObjet;
} //----- Fin de Objet (constructeur de copie)


Objet::Objet ( const string & unNom, const string & uneDescription )
    : nom(unNom), description(uneDescription)
// Algorithme :
//
{
    c=1;
#ifdef MAP
    cout << "#Appel au constructeur de <Objet>" << endl;
    cout << "#Nombre de réferences : " << c << endl << endl;
#endif

} //----- Fin de Objet


Objet::~Objet ( )
// Algorithme :
//
{
    c--;
    if (!c)
    {
        //TODO suppression du contenu;
    }
#ifdef MAP
    cout << "#Appel au destructeur de <Objet>" << endl;
    cout << "#Nombre de réferences : " << c << endl << endl;
#endif
} //----- Fin de ~Objet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
