/*************************************************************************
                                    Main
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse

*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"
#include "Historique.h"
#include "Rectangle.h"
#include "Segment.h"
#include "Polygone.h"
#include "Intersection.h"
#include "Union.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int main () {

	string requete;
	std::map<string,Objet*> objets;
	Historique histoCommande;

	while(true) {
		getline(cin, requete);
		istringstream iss(requete);
		string commande;
		iss >> commande;

		if(commande == "S" || commande == "s")
		{
			string name = "";
			iss >> name;
			int X1;
			int Y1;
			int X2;
			int Y2;
			if ((!(iss >> X1 && iss >> Y1 && iss >> X2 && iss >> Y2) || name == "") || !iss.eof())
			{
				cout << "ERR" << endl << "#Arguments invalides ou nombre d'arguments pas bon (5) !" << endl;
			}
			else
			{
				if(objets.size() == 0 || objets.count(name) == 0)
				{
					Point p1 (X1,Y1);
					Point p2 (X2,Y2);
					objets.insert(pair<string,Objet*>(name,new Segment(name, p1, p2)));
					histoCommande.add(requete);
					cout << "OK" << endl << "#Segment " + name + " créé" << endl;
				}
				else
				{
					cout << "ERR" << endl << "#L'objet existe déjà" << endl;
				}

			}

		}

		else if(commande == "R" || commande == "r")
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
			{
				if(objets.size() == 0 || objets.count(name) == 0)
				{
					Point p1 (X1,Y1);
					Point p2 (X2,Y2);
					objets.insert(pair<string,Objet*>(name,new Rectangle(name, p1, p2)));
					histoCommande.add(requete);
					cout << "OK" << endl << "#Segment " + name + " créé" << endl;
				}
				else
				{
					cout << "ERR" << endl << "#L'objet existe déjà" << endl;
				}

			}

		}

		else if(commande == "PC" || commande == "pc")
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
			{

				if(objets.size() == 0 || objets.count(name) == 0)
				{
					vector<Point> listPoints;
					for(unsigned int i=0; i<points.size()-1; i+=2)
					{
						Point p (points[i], points[i+1]);
						listPoints.push_back(p);
					}
					if (Polygone::EstConvexe(listPoints))
					{
						objets.insert(pair<string,Objet*>(name,new Polygone(listPoints, name)));
						histoCommande.add(requete);
						cout << "OK" << endl << "#Polygone " + name + " créé" << endl;
					}
					else
					{
						cout << "ERR" << endl << "#Polygone non convexe" << endl;
					}
				}
				else
				{
					cout << "ERR" << endl << "#L'objet existe déjà" << endl;
				}

			}

		}

		else if(commande == "OR" || commande == "or")
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
				cout << "ERR" << endl;
				cout << "#Veuillez indiquer le nom de la réunion";
				cout << "puis les noms d'objets existants" << endl;
				cout << "#constituant cette réunion !" << endl;

			}
			else
			{
				bool trouve = true;
				vector<Objet *> desObjets;
				for(string nameObj : names)
				{
					if(objets.size() == 0 || objets.count(nameObj) == 0)
					{
						cout << "ERR" << endl;
						cout << "#Il y a un objet qui n'existe pas !";
						cout << endl;
						trouve = false;
						break;
					}
					desObjets.push_back(objets.at(nameObj));
				}
				if (trouve)
				{
					objets[name]=new Union(name, desObjets);
					cout  << "OK" << endl;
					cout << "#Union "+name+" crée" << endl;
				}
			}
		}

		else if(commande == "OI" || commande == "oi")
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
				cout << "ERR" << endl;
				cout << "#Veuillez indiquer le nom de l'intersection";
				cout << " puis les noms d'objets existants" << endl;
				cout <<"#constituant cette réunion !" << endl;

			}
			else
			{
				bool trouve = true;
				vector<Objet *> desObjets;
				for(string nameObj : names)
				{
					if(objets.size() == 0 || objets.count(nameObj) == 0)
					{
						cout << "ERR" << endl;
						cout << "#Il y a un objet qui n'existe pas !";
						cout << endl;
						trouve = false;
						break;
					}
					desObjets.push_back(objets.at(nameObj));
				}
				if (trouve)
				{
					objets[name]=new Intersection(name, desObjets);
					cout  << "OK" << endl;
					cout << "#Intersection "+name+" crée" << endl;
				}
			}
		}

		else if(commande == "HIT" || commande == "hit")
		{
			string name = "";
			iss >> name;
			int X;
			int Y;
			if (!(iss >> X && iss >> Y) || name == "" || !iss.eof()) {
				cout << "ERR" << endl;
				cout << "#Argument invalide ou nombre d'arguments pas bon (3)!" << endl;

			}
			else if (objets.find(name) == objets.end())
			{
				cout << "ERR" << endl;
				cout << "#Objet inexistant" << endl;
			}
			else
			{
				Point p (X,Y);
				if (objets[name] -> Contient(p))
				{
					cout << "YES" << endl;
					cout << "#Le point " << p.ToString();
					cout << "est contenu dans " << name << endl;
				}
				else
				{
					cout << "NO" << endl;
					cout << "#Le point " << p.ToString();
					cout << "n’est pas contenu dans " << name << endl;
				}
			}

		}

		else if(commande == "DELETE" || commande == "delet")
		{
			vector<string> names;

			while(!iss.eof())
		    {
		        string nameObjet;
		        iss >> nameObjet;
		        names.push_back(nameObjet);
		    }

			if (names.size() == 0) {
				cout << "ERR" << endl;
				cout << "#Veuillez indiquer le nom de";
				cout << "l'intersection puis les noms d'objets";
				cout << "# existants constituant cette réunion !" << endl;

			}
			else
				cout << "OK" << endl;
		}

		else if(commande == "MOVE" || commande == "move")
		{
			string name = "";
			iss >> name;
			int dx;
			int dy;

			if ((!(iss >> dx && iss >> dy) || name == "") || !iss.eof()) {
				cout << "ERR" << endl;
				cout << "#Arguments invalides ou";
				cout << "nombre d'arguments pas bon (5)!" << endl;

			}
			else if (objets.count(name) == 0)
			{
				cout << "ERR" << endl;
				cout << "#Objet inexistant" << endl;
			}
			else
			{
				objets.at(name) -> Deplacer(*(new Point(dx,dy)));
			}
		}

		else if(commande == "LIST" || commande == "list")
		{
			if(!iss.eof())
			{
				cout << "ERR" << endl << "#Il n'y a pas d'argument, la commande est juste LIST." << endl;
			}
			else
			{

				// pour parcourir toutes les paires de la map
				std::map<string,Objet*>::const_iterator it;
				for (it=objets.begin() ; it!=objets.end() ; ++it)
				{
				    cout << it->second -> ToString() << endl;
				}
			}
		}

		else if(commande == "UNDO" || commande == "undo")
		{
			if(!iss.eof())
			{
				cout << "ERR" << endl << "#Il n'y a pas d'argument, la commande est juste UNDO." << endl;
			}
			else
			{
				cout << "OK" << endl;
			}
		}

		else if(commande == "REDO" || commande == "redo")
		{
			if(!iss.eof())
			{
				cout << "ERR" << endl << "#Il n'y a pas d'argument, la commande est juste REDO." << endl;
			}
			else
			{
				cout << "OK" << endl;
			}
		}

		else if(commande == "LOAD" || commande == "load")
		{
			string filename;
			iss >> filename;
			if(!iss.eof() || filename == "")
			{
				cout << "ERR" << endl << "#Pas le bon nombre d'arguments." << endl;
			}
			else
			{
				cout << "OK" << endl;
			}
		}

		else if(commande == "SAVE" || commande == "save")
		{
			string filename;
			iss >> filename;
			if(!iss.eof() || filename == "")
			{
				cout << "ERR" << endl << "#Pas le bon nombre d'arguments." << endl;
			}
			else
			{
				ofstream file (filename.c_str(), ios::out | ios::trunc);

				std::map<string,Objet*>::const_iterator it;
				for (it=objets.begin() ; it!=objets.end() ; ++it)
				{
				    file << it->second -> ToString() << endl;
				}
				cout << "OK" << endl;
			}
		}

		else if(commande == "CLEAR" || commande == "clear")
		{
			if(!iss.eof())
			{
				cout << "ERR" << endl << "#Il n'y a pas d'argument, la commande est juste CLEAR." << endl;
			}
			else
			{
				cout << "OK" << endl;
			}
		}

		else if(commande == "EXIT" || commande == "exit")
		{
			cout << "#BYE" << endl;
			break;
		}
		else
		{
			cout << "ERR" << endl << "#Commande inconnue !" << endl;
		}
	}
	return 0;
}

///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
