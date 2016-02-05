/*************************************************************************
                                    Dessin
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//---------------- Interface de la classe <Dessin> (fichier Dessin.h) ------
#ifndef DESSIN_H
#define DESSIN_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <deque>
#include <iomanip>
#include <map>
#include "Objet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Dessin>
//
//
//------------------------------------------------------------------------

class Dessin
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterObjet (string name, Objet* o);
    // Mode d'emploi :
    // Ajout de l'objet en paramètre au dessin.
    //
    // Contrat :
    // Ajoute l'objet au dessin si celui-ci n'existe pas déjà sur la figure.

    bool verifObjetsPresents (vector<string> names);
    // Mode d'emploi :
    // Vérifie que tout les objets passés en paramètre sont dans le dessin.
    //
    // Contrat :
    // Vérifie que tout les objets passés en paramètre sont dans le dessin.

     bool isObjetPresent (string name);
    // Mode d'emploi :
    // Vérifie que l'objet passé en paramètre est dans le dessin.
    //
    // Contrat :
    // Vérifie que l'objet passé en paramètre est dans le dessin.

    void Delete(vector<string> names);
    // Mode d'emploi :
    // Supprime tous les objets passés en paramètre.
    //
    // Contrat :
    // Supprime tous les objets passés en paramètre.

    void DeplacerObjet (string name, Point p);
    // Mode d'emploi :
    // Déplace l'objet selon l'axe x et y.
    //
    // Contrat :
    // Vérifie que l'objet passé en paramètre est dans le dessin.

    bool Contient(string name, Point p);
    // Mode d'emploi :
    // Vérifie pour l'objet si le point est contenu dedans ou non.
    //
    // Contrat :
    // Vérifie pour l'objet si le point est contenu dedans ou non.

    void Afficher();
    // Mode d'emploi :
    // Affiche tous les objets du dessin actuel.
    //
    // Contrat :
    // Affiche tous les objets du dessin actuel.

    void Save(string fileName);
    // Mode d'emploi :
    // Sauve l'état du dessin actuel dans le fichier correspondant au nom.
    //
    // Contrat :
    // Sauve l'état du dessin actuel dans le fichier correspondant au nom.

    vector<string> Load(string fileName);
    // Mode d'emploi :
    // Charge un fichier pour construire le dessin.
    //
    // Contrat :
    // Quand on l'appelle on détruit tous les objets existants.

    void Clear();
    // Mode d'emploi :
    // Supprime tous les objets du dessin actuel.
    //
    // Contrat :
    // Supprime tous les objets du dessin actuel.

    Objet* getObjet(string name);
    // Mode d'emploi :
    // Renvoie le pointeur vers l'objet name.
    //
    // Contrat :
    // Renvoie le pointeur vers l'objet name.

    string getDescription(string name);
    // Mode d'emploi :
    // Renvoie la description de l'objet.
    //
    // Contrat :
    // -.

    vector<string> getDescriptions();
    // Mode d'emploi :
    // Renvoie un vector de string contenant toutes les descriptions.
    //
    // Contrat :
    // -.

   
//------------------------------------------------- Surcharge d'opérateurs
    
//-------------------------------------------- Constructeurs - destructeur
    Dessin ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    
    virtual ~Dessin ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
       
protected:
//----------------------------------------------------- Attributs protégés
   

private:
//------------------------------------------------------- Attributs privés
    map<string,Objet*>* objets;
    
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Dessin>

#endif // DESSIN_H
