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

void Historique::add (const vector<string> commande)
// Algorithme :
//
{
	if(commandesUndo.size() == 20)
	{
		commandesUndo.pop_front();
	}	
	commandesUndo.push_back(commande);
	
} //----- Fin de add()

void Historique::addRedo (const vector<string> commande)
// Algorithme :
//
{
	if(commandesRedo.size() == 20)
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

vector<string> Historique::getCommandeUndo ()
// Algorithme :
//
{
	vector<string> commande;
	if(commandesUndo.size() == 0)
	{
		commande.push_back("ERR1");
		return commande;		         
	}
	else
	{
		commande = commandesUndo.back();
		commandesUndo.pop_back();

		return commande;
	}
	
} //----- Fin de add()

vector<string> Historique::getCommandeRedo ()
// Algorithme :
//
{
	vector<string> commande;
	if(commandesRedo.size() == 0)
	{
		commande.push_back("ERR2");
		return commande;		         
	}
	else
	{
		commande = commandesRedo.back();
		commandesRedo.pop_back();
		return commande;
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
