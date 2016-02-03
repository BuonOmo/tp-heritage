/*************************************************************************
                                    Main
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse

*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
/*#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <fstream>*/
using namespace std;

//------------------------------------------------------ Include personnel
#include "Commande.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int main () {

	string requete;
	Commande *commande = new Commande();

	while(true) {
		getline(cin, requete);
		if(!commande->execute(requete))
			break;
	}
	delete commande;
	return 0;
}

///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
