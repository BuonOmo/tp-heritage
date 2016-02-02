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

    void AjouterObjetsComplexes (string name, vector<string> names, int type);
    // Mode d'emploi :
    // Ajout d'un objet complexe qui sera soit une union (type 1) ou alors
    // une intersection (type 2). Ces objets sont construits à partir d'une liste d'objets
    // existants.
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

    void Undo();
    // Mode d'emploi :
    // Annule l'action de modification précédente.
    //
    // Contrat :
    // Annule l'action de modification précédente.
    
    void Redo();
    // Mode d'emploi :
    // Annule le undo précédent si il n'y a eu aucune modification entre.
    //
    // Contrat :
    // Annule le undo précédent si il n'y a eu aucune modification entre.

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

    void Clear();
    // Mode d'emploi :
    // Supprime tous les objets du dessin actuel.
    //
    // Contrat :
    // Supprime tous les objets du dessin actuel.

   
//------------------------------------------------- Surcharge d'opérateurs
    Dessin & operator = ( const Dessin & unDessin );



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
    void viderEtatSuivants();
    // Mode d'emploi :
    // Vide la pile des etats suivants pour le redo.
    //
    // Contrat :
    // Vide la pile.

    void viderEtatPrecedents();
    // Mode d'emploi :
    // Vide la pile des etats precedents pour le undo.
    //
    // Contrat :
    // Vide la pile.
    
protected:
//----------------------------------------------------- Attributs protégés
   

private:
//------------------------------------------------------- Attributs privés
    map<string,Objet*>* objets;
    //Historique histoCommande;
   
    deque<map<string,Objet*>>* etatPrecedent;
    deque<map<string,Objet*>>* etatSuivant;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Dessin>

#endif // DESSIN_H