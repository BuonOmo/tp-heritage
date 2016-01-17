/*************************************************************************
                                    Main
                             -------------------
    début                )
   {
	
   } 12 janvier 2016
    copyright            )
   {
	
   } (C) 2016 par Pierre et Ulysse
*************************************************************************/

///---------- Réalisation de la classe <Main> (fichier Main.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
			
		if(commande == "S")
		{
			string name = "";
			iss >> name;
			int X1;
			int Y1;
			int X2;
			int Y2;
			if ((!(iss >> X1 && iss >> Y1 && iss >> X2 && iss >> Y2) || name == "") || !iss.eof() ) {
				cout << "ERR" << endl << "#Arguments invalides ou nombre d'arguments pas bon (5) !" << endl;
				
			}
			else
				cout << name << " " << X1 << " " << Y1 << " " << X2 << " " << Y2 << " OK" << endl;
		}
				
		else if(commande == "R")
		{
			string name = "";
			iss >> name;
			int X1;
			int Y1;
			int X2;
			int Y2;
			if ((!(iss >> X1 && iss >> Y1 && iss >> X2 && iss >> Y2) || name == "") || !iss.eof() ) {
				cout << "ERR" << endl << "#Arguments invalides ou nombre d'arguments pas bon (5)!" << endl;
				
			}
			else
				cout << name << " " << X1 << " " << Y1 << " " << X2 << " " << Y2 << " OK" << endl;
		}
		
		else if(commande == "PC")
		{
			string name = "";
			iss >> name;
			vector<int> points;
			bool coordOk = true;
			while(!iss.eof())
		    {
		        int coord;
		        if(!(iss >> coord))
		        {
		        	coordOk = false;
		        	break;
		        }
		        
		        points.push_back(coord);

		    }
		    
			if (!coordOk || points.size() < 6 || name == "" || !(points.size()%2 == 0)) {
				cout << "ERR" << endl << "#Arguments invalides ou nombre d'arguments pas bon !" << endl;
				
			}
			else
				cout << "OK" << endl;
		}
		
		else if(commande == "OR")
		{
			string name = "";
			iss >> name;
			vector<string> names;
			
			while(!iss.eof())
		    {
		        string nameObjet;
		        iss >> nameObjet;		        
		        names.push_back(nameObjet);
		    }
		    
			if (names.size() == 0 || name == "") {
				cout << "ERR" << endl << "#Veuillez indiquer le nom de la réunion puis les noms d'objets existants constituant cette réunion !" << endl;
				
			}
			else
				cout << "OK" << endl;
		}
		
		else if(commande == "OI")
		{
			string name = "";
			iss >> name;
			vector<string> names;
			
			while(!iss.eof())
		    {
		        string nameObjet;
		        iss >> nameObjet;		        
		        names.push_back(nameObjet);
		    }
		    
			if (names.size() == 0 || name == "") {
				cout << "ERR" << endl << "#Veuillez indiquer le nom de l'intersection puis les noms d'objets existants constituant cette réunion !" << endl;
				
			}
			else
				cout << "OK" << endl;
		}
		
		else if(commande == "HIT")
		{
			string name = "";
			iss >> name;
			int X;
			int Y;
			if (!(iss >> X && iss >> Y) || name == "" || !iss.eof()) {
				cout << "ERR" << endl << "#Arguments invalides ou nombre d'arguments pas bon (3)!" << endl;
				
			}
			else
				cout << name << " " << X << " " << Y << " OK" << endl;
		}
		
		else if(commande == "DELETE")
		{

		}
		
		else if(commande == "MOVE")
		{

		}
		
		else if(commande == "LIST")
		{

		}
		
		else if(commande == "UNDO")
		{

		}
		
		else if(commande == "REDO")
		{

		}
		
		else if(commande == "LOAD")
		{

		}
		
		else if(commande == "SAVE")
		{

		}
		
		else if(commande == "CLEAR")
		{

		}
		
		else if(commande == "EXIT")
		{
			cout << "#BYE" << endl;
			break;			
		}
		else 
		{
			cout << "ERR" << endl << "#Commande inconnue !" << endl;
			break;
		}	
	}
	return 0;
}

///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
