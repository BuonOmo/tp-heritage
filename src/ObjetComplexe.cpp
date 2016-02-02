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
        objets.clear();
        for (Objet * o : unObjetComplexe.objets)
        {
            objets.push_back(o -> Copier());
        }
        nom = unObjetComplexe.nom;
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ObjetComplexe::ObjetComplexe ( const ObjetComplexe & unObjetComplexe )
// Algorithme :
//
{
#ifdef MAP
    cout << "#Appel au constructeur de copie de <ObjetComplexe>" << endl;
#endif
    *this = unObjetComplexe;
} //----- Fin de ObjetComplexe (constructeur de copie)

void ObjetComplexe::Renommer ( const string & nouveauNom )
{
#ifdef MAP
    cout << "Appel à la méthode Renommer de <ObjetComplexe>" << endl;
#endif
    string tmp;
    if (nouveauNom.find(nom) != string::npos)
    {
        for (Objet * o : objets)
        {
            tmp=o->GetNom();
            o -> Renommer(nouveauNom + tmp.substr(tmp.find('_')));
        }
    }
    else
    {
        for (Objet * o : objets)
        {
            tmp=o->GetNom();
            o -> Renommer(nouveauNom+"_"+tmp);
        }
    }
    nom = nouveauNom;
} //----- Fin de Renommer

ObjetComplexe::ObjetComplexe (  const string & unNom,
                                const vector<Objet *> &desObjets )
    : Objet(unNom)
// Algorithme :
//
{
    for (Objet * o : desObjets)
    {
        objets.push_back(o -> Copier());
    }
    for (Objet * o : objets)
    {
        // test permettant d’eviter le double rennomage sur un
        // save/load/save
         if (o -> GetNom().find(unNom+"_") == string::npos)
         {
             o -> Renommer (unNom + "_"+o -> GetNom());
         }
    }
#ifdef MAP
    cout << "#Appel au constructeur de <ObjetComplexe>" << endl;
#endif
} //----- Fin de ObjetComplexe


ObjetComplexe::~ObjetComplexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "#Appel au destructeur de <ObjetComplexe>" << endl;
#endif
    for (Objet * o : objets)
    {
        delete o;
    }
} //----- Fin de ~ObjetComplexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
