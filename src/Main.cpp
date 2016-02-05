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
#include <cstdio>
#include <ctime>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int main () {

	string entreeClavier;
	Commande *commande = new Commande();
	
	while(true) {
		getline(cin, entreeClavier);
		vector<string> requetes;
		requetes.push_back(entreeClavier);

		if(!commande->execute(requetes, false, false))
			break;
	}
	delete commande;
	return 0;
}

///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
