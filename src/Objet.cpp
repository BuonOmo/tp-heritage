/*************************************************************************
                                    Objet
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//------------ Réalisation de la classe <Objet> (fichier Objet.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Objet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Objet::GetNom ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode GetNom de <Objet>" << endl;
#endif
    return nom;
} //----- Fin de GetNom

void Objet::Renommer ( const string & nouveauNom )
{
#ifdef MAP
    cout << "#Appel à la méthode Renommer de <Objet>" << endl;
#endif
    nom = nouveauNom;
} //----- Fin de Renommer

//------------------------------------------------- Surcharge d'opérateurs
Objet & Objet::operator = ( const Objet & unObjet )
{
    if (this != &unObjet)
    {
        nom = unObjet.nom;
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Objet::Objet ( const Objet & unObjet )
{
    c++;
#ifdef MAP
    cout << "#Appel au constructeur de copie de <Objet>" << endl;
    cout << "#Nombre de réferences : " << c << endl;
#endif
    *this = unObjet;
} //----- Fin de Objet (constructeur de copie)


Objet::Objet ( const string & unNom )
    : nom(unNom)
{
    c=1;
#ifdef MAP
    cout << "#Appel au constructeur de <Objet>" << endl;
    cout << "#Nombre de réferences : " << c << endl;
#endif

} //----- Fin de Objet


Objet::~Objet ( )
{
    c--;
    /*if (!c)
    {
        //TODO suppression du contenu;
    }*/
#ifdef MAP
    cout << "#Appel au destructeur de <Objet>" << endl;
    cout << "#Nombre de réferences : " << c << endl;
#endif
} //----- Fin de ~Objet
