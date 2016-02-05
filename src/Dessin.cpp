/*************************************************************************
                                    Dessin
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//------------ Réalisation de la classe <Dessin> (fichier Dessin.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Dessin.h"
#include "Union.h"
#include "Intersection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Dessin::AjouterObjet (string name, Objet* o)
// Algorithme :
//
{
    objets->insert(pair<string,Objet*>(name,o));
}


bool Dessin::Contient(string name, Point p)
// Algorithme :
//
{
    return objets->at(name)->Contient(p);
}

bool Dessin::verifObjetsPresents (vector<string> names)
// Algorithme :
//
{
    for(string name : names)
    {
        if(!isObjetPresent(name))
            return false;
    }
    return true;
}

 bool Dessin::isObjetPresent (string name)
// Algorithme :
//
{
    return !(objets->size() == 0 || objets->count(name) == 0);
}

void Dessin::Delete(vector<string> names)
// Algorithme :
//
{
    for(string name : names)
    {
        delete objets->at(name);
        objets->erase(name);
    }        
}

void Dessin::DeplacerObjet (string name, Point p)
// Algorithme :
//
{
    objets->at(name)->Deplacer(p);    
}

void Dessin::Afficher() 
// Algorithme :
//
{
    if (objets->size() == 0)
        cout << "#Aucuns objets présents" << endl;
    else
    {
        for(map<string,Objet*>::iterator it=objets->begin(); it!=objets->end(); ++it)
        {
            cout << it->second -> ToString() << endl;
        } 
    }
    
}

void Dessin::Save(string filename) 
// Algorithme :
//
{
    ofstream file (filename.c_str(), ios::out | ios::trunc);
    for(map<string,Objet*>::iterator it=objets->begin(); it!=objets->end(); ++it)
    {
        file << it->second -> ToString() << endl;
    }
}

vector<string> Dessin::Load(string filename) 
// Algorithme :
//
{
    Clear();
    ifstream fichier(filename.c_str());
    vector<string> vecCom;
    while(fichier)
    {
        string ligne;
        getline(fichier, ligne);
        vecCom.push_back(ligne);
    }
    return vecCom;
}

void Dessin::Clear()
// Algorithme :
//
{
    for(map<string,Objet*>::iterator it=objets->begin(); it!=objets->end(); ++it)
    {        
        delete it->second;        
    }
    objets->clear();   
}

Objet* Dessin::getObjet(string name)
// Algorithme :
//
{
    return objets->at(name);
}

string Dessin::getDescription(string name)
// Algorithme :
//
{
    return objets->at(name)->ToString();
}

vector<string> Dessin::getDescriptions()
// Algorithme :
//
{
    vector<string> desc;
    for(map<string,Objet*>::iterator it=objets->begin(); it!=objets->end(); ++it)
    {        
        desc.push_back(it->second->ToString());        
    }
    return desc;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Dessin::Dessin ()
// Algorithme :
//
{

    objets = new map<string,Objet*>();    
#ifdef MAP
    cout << "#Appel au constructeur de copie de <Dessin>" << endl;
    cout << "#Nombre de réferences : " << c << endl << endl;
#endif
    
} //----- Fin de Dessin (constructeur de copie)


Dessin::~Dessin ( )
// Algorithme :
//
{
    Clear();
    delete objets;

#ifdef MAP
    cout << "#Appel au destructeur de <Dessin>" << endl;
    cout << "#Nombre de réferences : " << c << endl << endl;
#endif
} //----- Fin de ~Dessin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
