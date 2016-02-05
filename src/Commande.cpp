/*************************************************************************
                        Commande  -  Listes des commandes
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//---- Réalisation de la classe <Commande> (fichier Commande.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Commande.h"
#include "Polygone.h"
#include "Segment.h"
#include "Rectangle.h"
#include "Union.h"
#include "Intersection.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

bool Commande::execute (const vector<string> requete, bool undo, bool redo)
// Algorithme :
//
{
	if(requete.size() <= 1)
	{
		string commande = requete.front();
		istringstream iss(commande);
		vector<string> commandesAUndo;
		string commandeUndo;
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
				cout << "ERR" << endl
					 << "#Arguments invalides ou nombre d'arguments pas bon (5) !"
					 << endl;
			}
			else
			{
				if(!dessin->isObjetPresent(name))
				{
					Point p1 (X1,Y1);
					Point p2 (X2,Y2);
					cout << "OK" << endl
						 << "#Segment " + name + " créé" << endl;
					dessin->AjouterObjet(name,new Segment(name, p1, p2));
					commandeUndo = "DELETE " + name;
					commandesAUndo.push_back(commandeUndo);
					if(!undo)
					{
						histo->add(commandesAUndo);
						if(!redo)
							histo->viderRedo();
					}
					else
						histo->addRedo(commandesAUndo);
				}
				else
				{
					cout << "ERR" << endl
						 << "#L'objet "<< name <<" existe déjà" << endl;
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
				cout << "ERR" << endl
					 << "#Arguments invalides ou nombre d'arguments pas bon (5)!" << endl;

			}
			else
			{
				if(!dessin->isObjetPresent(name))
				{
					Point p1 (X1,Y1);
					Point p2 (X2,Y2);
					cout << "OK" << endl
						 << "#Rectangle " + name + " créé" << endl;
					dessin->AjouterObjet(name,new Rectangle(name, p1, p2));
					commandeUndo = "DELETE " + name;
					commandesAUndo.push_back(commandeUndo);
					if(!undo)
					{
						histo->add(commandesAUndo);
						if(!redo)
							histo->viderRedo();
					}
					else
						histo->addRedo(commandesAUndo);
				}
				else
				{
					cout << "ERR" << endl
						 << "#L'objet "<<name<<" existe déjà" << endl;
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
				cout << "ERR" << endl
					 << "#Arguments invalides ou nombre d'arguments pas bon !" << endl;

			}
			else
			{

				if(!dessin->isObjetPresent(name))
				{
					vector<Point> listPoints;
					for(unsigned int i=0; i<points.size()-1; i+=2)
					{
						Point p (points[i], points[i+1]);
						listPoints.push_back(p);
					}
					if (Polygone::EstConvexe(listPoints))
					{

						cout << "OK" << endl
							 << "#Polygone " + name + " créé" << endl;
						dessin->AjouterObjet(name,new Polygone(listPoints, name));
						commandeUndo = "DELETE " + name;
						commandesAUndo.push_back(commandeUndo);
						if(!undo)
						{
							histo->add(commandesAUndo);
							if(!redo)
								histo->viderRedo();
						}
						else
							histo->addRedo(commandesAUndo);
					}
					else
					{
						cout << "ERR" << endl
							 << "#Le Polygone "<<name<<" est non convexe" << endl;
					}
				}
				else
				{
					cout << "ERR" << endl
						 << "#L’objet "<<name<<" existe déjà" << endl;
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
			else if (dessin->isObjetPresent(name))
			{
				cout << "ERR" << endl
					 << "#L’objet "<<name<<" existe déjà" << endl;
			}
			else
			{
				bool trouve = true;
			    vector<Objet *> desObjets;
			    for(string nameObj : names)
			    {
			        if(!dessin->isObjetPresent(nameObj))
			        {
			            cout << "ERR" << endl;
			            cout << "#L’objet "+nameObj+" n'existe pas !";
						cout << endl;
						cout << "#Impossible de créer l’union.";
			            cout << endl;
			            trouve = false;
			            break;
			        }
			        desObjets.push_back(dessin->getObjet(nameObj));
			    }
			    if (trouve)
			    {
		            dessin->AjouterObjet(name,new Union(name, desObjets));
		            cout  << "OK" << endl;
		            cout << "#Union "+name+" crée" << endl;
		            commandeUndo = "DELETE " + name;
		            commandesAUndo.push_back(commandeUndo);
					if(!undo)
					{
						histo->add(commandesAUndo);
						if(!redo)
							histo->viderRedo();
					}
					else
						histo->addRedo(commandesAUndo);
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
			else if (dessin->isObjetPresent(name))
			{
				cout << "ERR" << endl
					 << "#L’objet "+name+" existe déjà" << endl;
			}
			else
			{
				bool trouve = true;
			    vector<Objet *> desObjets;
			    for(string nameObj : names)
			    {
			        if(!dessin->isObjetPresent(nameObj))
			        {
						cout << "ERR" << endl;
			            cout << "#L’objet "+nameObj+" n'existe pas !";
						cout << endl;
						cout << "#Impossible de créer l’intersection.";
			            cout << endl;
			            trouve = false;
			            break;
			        }
			        desObjets.push_back(dessin->getObjet(nameObj));
			    }
			    if (trouve)
			    {
		            dessin->AjouterObjet(name,new Intersection(name, desObjets));
		            cout  << "OK" << endl;
		            cout << "#Intersection "+name+" crée" << endl;
		            commandeUndo = "DELETE " + name;
		            commandesAUndo.push_back(commandeUndo);
					if(!undo)
					{
						histo->add(commandesAUndo);
						if(!redo)
							histo->viderRedo();
					}
					else
						histo->addRedo(commandesAUndo);
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
			else if (!dessin->isObjetPresent(name))
			{
				cout << "ERR" << endl;
				cout << "#Objet "+name+" inexistant" << endl;
			}
			else
			{
				Point p (X,Y);
				if (dessin->Contient(name,p))
				{
					cout << "YES" << endl;
					cout << "#Le point " << p;
					cout << " est contenu dans " << name << endl;
				}
				else
				{
					cout << "NO" << endl;
					cout << "#Le point " << p;
					cout << " n’est pas contenu dans " << name << endl;
				}
			}

		}

		else if(commande == "DELETE" || commande == "delete")
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
			else if(dessin->verifObjetsPresents(names))
			{
				cout << "OK" << endl;
				executeDescription(names, undo, redo);
				dessin->Delete(names);

			}
			else
			{
				cout << "ERR" << endl
					 << "#Un ou des objets n'existent pas !" << endl;
			}
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
			else if (!dessin->isObjetPresent(name))
			{
				cout << "ERR" << endl;
				cout << "#Objet "+name+" inexistant" << endl;
			}
			else
			{
				Point * p = new Point(dx,dy);
				dessin->DeplacerObjet(name,*p);
				delete p;
				cout << "OK" << endl;
				dx = -dx;
				dy = -dy;
				commandeUndo = "MOVE " + name + " " + to_string(dx) + " " + to_string(dy);
				commandesAUndo.push_back(commandeUndo);
				if(!undo)
				{
					histo->add(commandesAUndo);
					if(!redo)
						histo->viderRedo();
				}
				else
					histo->addRedo(commandesAUndo);
			}
		}

		else if(commande == "LIST" || commande == "list")
		{
			if(!iss.eof())
			{
				cout << "ERR" << endl
					 << "#Il n'y a pas d'argument, la commande est juste LIST." << endl;
			}
			else
			{
				dessin->Afficher();
			}
		}

		else if(commande == "UNDO" || commande == "undo")
		{
			if(!iss.eof())
			{
				cout << "ERR" << endl
					 << "#Il n'y a pas d'argument, la commande est juste UNDO." << endl;
			}
			else
			{
				execute(histo->getCommandeUndo(), true);
			}
		}

		else if(commande == "REDO" || commande == "redo")
		{
			if(!iss.eof())
			{
				cout << "ERR" << endl
					 << "#Il n'y a pas d'argument, la commande est juste REDO." << endl;
			}
			else
			{
				execute(histo->getCommandeRedo(), false, true);
			}
		}

		else if(commande == "LOAD" || commande == "load")
		{
			string filename;
			iss >> filename;
			if(!iss.eof() || filename == "")
			{
				cout << "ERR" << endl
					 << "#Pas le bon nombre d'arguments." << endl;
			}
			else
			{
				commandeUndo = "CLEAR";
				commandesAUndo.push_back(commandeUndo);
				if(!undo)
				{
					histo->add(commandesAUndo);
					if(!redo)
						histo->viderRedo();
				}
				else
					histo->addRedo(commandesAUndo);
				bool fichierPresent = true;
				vector<string> loadCommandes = dessin->Load(filename);
				for(string com : loadCommandes)
				{
					if(com == "ERR3")
					{
						fichierPresent = false;
						break;
					}
					loadObjet(com);
				}
				if(fichierPresent)
				{
					cout << "OK" << endl;
				}
				else
				{
					cout << "ERR" << endl
						 << "#Le fichier est introuvable"
						 << endl;
				}
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
				dessin->Save(filename);
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

				commandesAUndo = dessin->getDescriptions();
				if(!undo)
				{
					histo->add(commandesAUndo);
					if(!redo)
						histo->viderRedo();
				}
				else
				{
					histo->addRedo(commandesAUndo);
				}
				dessin->Clear();
				cout << "OK" << endl;
			}
		}

		else if(commande == "EXIT" || commande == "exit")
		{
			cout << "#BYE" << endl;
			return false;
		}

		else if(commande == "ERR1")
		{
			cout << "ERR" << endl << "#Pas de commande à annuler" << endl;
		}

		else if(commande == "ERR2")
		{
			cout << "ERR" << endl << "#Pas de commande annulée à annuler" << endl;
		}

		else
		{
			cout << "ERR" << endl << "#Commande inconnue !" << endl;
		}
	}
	else
	{
		vector<string> names;
		for (string commande : requete)
		{
			if(commande != "ADD")
			{
				istringstream iss(commande);
				stringstream ss(commande);
			    string item;
			    vector<string> tokens;
			    while (getline(ss, item, ' ')) {
			        tokens.push_back(item);
	    		}
	    		string nom = tokens[1];
	    		names.push_back(nom);
	    		loadObjet(commande);
			}
			else
				continue;

		}
		vector<string> commandesAUndo;
		string commandeUndo = "DELETE";
		for(string name : names)
			commandeUndo += " " + name;
		commandesAUndo.push_back(commandeUndo);
		if(!undo)
		{
			histo->add(commandesAUndo);
			if(!redo)
				histo->viderRedo();

		}
		else
		{
			histo->addRedo(commandesAUndo);
		}

		cout << "OK" << endl;
	}
	return true;

} //----- Fin de add()

void Commande::executeDescription(vector<string> names, bool undo, bool redo)
// Algorithme :
//
{
	vector<string> commandesAUndo;
	string commande = "ADD";
	commandesAUndo.push_back(commande);
	for (string name : names)
	{
		commandesAUndo.push_back(dessin->getDescription(name));
	}
	if(!undo)
	{
		histo->add(commandesAUndo);
		if(!redo)
			histo->viderRedo();
	}
	else
		histo->addRedo(commandesAUndo);
}


bool Commande::loadObjet (string description)
{
    stringstream ss(description);
    string item;
    vector<string> tokens;
    while (getline(ss, item, ' ')) {
        tokens.push_back(item);
    }
    if(tokens.size() == 0)
    {
        return false;
    }
    string nom = tokens[1];
    if(tokens[0] == "S")
    {
        Segment * seg = new Segment(nom);
        seg->AddPoint(Point(atoi(tokens[2].c_str()), atoi(tokens[3].c_str())));
        seg->AddPoint(Point(atoi(tokens[4].c_str()), atoi(tokens[5].c_str())));
        if (dessin->isObjetPresent(nom))
        {
            return false;
        }
        dessin->AjouterObjet(nom, seg);
    }
    else if(tokens[0] == "R")
    {
        Rectangle * rect = new Rectangle(nom);
        rect->AddPoint(Point(atoi(tokens[2].c_str()), atoi(tokens[3].c_str())));
        rect->AddPoint(Point(atoi(tokens[4].c_str()), atoi(tokens[5].c_str())));
        if (dessin->isObjetPresent(nom))
        {
            return false;
        }
        dessin->AjouterObjet(nom, rect);
    }
    else if(tokens[0] == "PC")
    {
        Polygone * pol = new Polygone(nom);
        for(int i = 3; i < atoi(tokens[2].c_str())*2+3; i += 2)
        {
        	pol->AddPoint(Point(atoi(tokens[i].c_str()), atoi(tokens[i+1].c_str())));
        }
        if (dessin->isObjetPresent(nom))
        {
            return false;
        }
        dessin->AjouterObjet(nom, pol);

    }
    else if(tokens[0] == "OR")
    {
        Union * reu = new Union(nom);
        int pos = 3;
        for(int i = 0; i < atoi(tokens[2].c_str()); ++i)
        {
            pos = loadObjetIntoObjetComplexe (reu, tokens, pos);
        }
        if (dessin->isObjetPresent(nom))
        {
            return false;
        }
        dessin->AjouterObjet(nom, reu);
    }
    else if(tokens[0] == "OI")
    {
        Intersection * intersect = new Intersection(nom);
        int pos = 3;
        for(int i = 0; i < atoi(tokens[2].c_str()); ++i)
        {
            pos = loadObjetIntoObjetComplexe (intersect, tokens, pos);
        }
        if (dessin->isObjetPresent(nom))
        {
            return false;
        }
        dessin->AjouterObjet(nom, intersect);
    }
    return true;
}

int Commande::loadObjetIntoObjetComplexe (ObjetComplexe * objComp, const vector<string> & tokens, int pos)
{
	string nomObj = tokens[pos+1];
    if(tokens[pos] == "S")
    {
    	Segment * seg = new Segment(nomObj);
        seg->AddPoint(Point(atoi(tokens[pos+2].c_str()), atoi(tokens[pos+3].c_str())));
        seg->AddPoint(Point(atoi(tokens[pos+4].c_str()), atoi(tokens[pos+5].c_str())));
        objComp->AddObjet(seg);
        return pos + 6;
    }
    else if(tokens[pos] == "R")
    {
        Rectangle * rect = new Rectangle(nomObj);
        rect->AddPoint(Point(atoi(tokens[pos+2].c_str()), atoi(tokens[pos+3].c_str())));
        rect->AddPoint(Point(atoi(tokens[pos+4].c_str()), atoi(tokens[pos+5].c_str())));
        objComp->AddObjet(rect);
        return pos + 6;
    }
    else if(tokens[pos] == "PC")
    {
        Polygone * pol = new Polygone(nomObj);
        for(int i = pos+3; i < atoi(tokens[pos+2].c_str())*2+pos+3; i += 2)
        {
            pol->AddPoint(Point(atoi(tokens[i].c_str()), atoi(tokens[i+1].c_str())));
        }
        objComp->AddObjet(pol);
        return pos + 3 + atoi(tokens[pos + 2].c_str())*2;
    }
    else if(tokens[pos] == "OR")
    {
        int posLocal = pos + 3;
        Union * reu = new Union(nomObj);
        for(int i = 0; i < atoi(tokens[pos+2].c_str()); ++i)
        {
            posLocal = loadObjetIntoObjetComplexe (reu, tokens, posLocal);
        }
        objComp->AddObjet(reu);
        return posLocal;
    }
    else if(tokens[pos] == "OI")
    {
        int posLocal = pos + 3;
        Intersection * intersect = new Intersection(nomObj);
        for(int i = 0; i < atoi(tokens[pos+2].c_str()); ++i)
        {
            posLocal = loadObjetIntoObjetComplexe (intersect, tokens, posLocal);
        }
        objComp->AddObjet(intersect);
        return posLocal;
    }
    return 3;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Commande::Commande ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Commande>" << endl;
#endif
    dessin = new Dessin();
    histo = new Historique();

} //----- Fin de Commande ()


Commande::~Commande ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Commande>" << endl;
#endif
    delete dessin;
    delete histo;
} //----- Fin de ~Commande


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
