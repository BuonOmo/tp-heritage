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
	if(commandesUndo.size() == 10)
	{
		commandesUndo.pop_front();
	}	
	commandesUndo.push_back(commande);
	
} //----- Fin de add()

void Historique::addRedo (const string commande)
// Algorithme :
//
{
	if(commandesRedo.size() == 10)
	{
		commandesRedo.pop_front();
	}	
	commandesRedo.push_back(commande);
	
} //----- Fin de add()

void Historique::viderRedo ()
// Algorithme :
//
{
	if(!commandesRedo.size() == 0)
	{
		commandesRedo.clear();
	}	
} //----- Fin de add()

string Historique::getCommandeUndo ()
// Algorithme :
//
{
	if(commandesUndo.size() == 0)
	{
		return "ERR1";		         
	}
	else
	{
		return commandesUndo.back();
	}
	
} //----- Fin de add()

string Historique::getCommandeRedo ()
// Algorithme :
//
{
	if(commandesRedo.size() == 0)
	{
		return "ERR2";		         
	}
	else
	{
		return commandesRedo.back();
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
