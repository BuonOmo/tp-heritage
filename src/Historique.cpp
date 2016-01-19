/*************************************************************************
                        Historique  -  Listes des commandes
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//---- Réalisation de la classe <Historique> (fichier Historique.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Historique.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Historique::add (const string commande)
// Algorithme :
//
{
	if(commandes.size() == 20) 
	{
		commandes.pop_front();
		         
	}
	commandes.push_back(commande);
	
} //----- Fin de add()

void Historique::undo ()
// Algorithme :
//
{
	if(commandes.size() == 0) 
	{
		cout << "ERR" << endl << "#Pas de commandes a annulé !" << endl;
		         
	}
	else
	{
		commandes.pop_back();
	}
	
} //----- Fin de add()


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Historique::Historique ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Historique>" << endl;
#endif
    
} //----- Fin de Historique ()


Historique::~Historique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Historique>" << endl;
#endif
} //----- Fin de ~Historique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
