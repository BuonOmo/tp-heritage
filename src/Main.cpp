/*************************************************************************
                                    Main
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

///---------- Réalisation de la classe <Main> (fichier Main.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

///------------------------------------------------------ Include personnel


///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe

///----------------------------------------------------------- Types privés


///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- Méthodes publiques

int main () {
	
	string requete;
	while(true) {		
		getline(cin, requete);
		istringstream iss(requete);
		string commande;
		iss >> commande;
		
		switch(commande) {
			
			case "S":
			
			case "R":
			
			case "PC":
			
			case "OR":
			
			case "OI":
			
			case "HIT":
			
			case "DELETE":
			
			case "MOVE":
			
			case "LIST":
			
			case "UNDO":
			
			case "REDO":
			
			case "LOAD":
			
			case "SAVE":
			
			case "CLEAR":
			
			case "EXIT":
				cout << "#BYE" << endl;
				break;
				
			default :
				cout << "ERR" << endl << "#Commande inconnue !" << endl;
				break;
			
		}
	}
	
	
	
	return 0;
}

///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
