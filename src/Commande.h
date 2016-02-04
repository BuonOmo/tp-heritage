/*************************************************************************
                           Commande  -  gestion de la liste des commandes
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Interface de la classe <Commande> (fichier Commande.h) ----------
#ifndef COMMANDE_H
#define COMMANDE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <deque>
#include <iomanip>
#include "Dessin.h"
#include "Historique.h"
#include "ObjetComplexe.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Commande>
//
//
//------------------------------------------------------------------------

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool execute (const vector<string> commande, 
                  bool undo = false, 
                  bool redo = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void executeCommande (const string commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void executeDescription (vector<string> objectNames, bool undo = false, bool redo = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool loadObjet (string description);
    // Mode d'emploi :
    //
    // Contrat :
    //
        
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Commande ();
    // Mode d'emploi () :
    //
    // Contrat :
    //

    
    virtual ~Commande ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    int loadObjetIntoObjetComplexe (ObjetComplexe * objComp, 
                                    const vector<string> & tokens, 
                                    int pos);
    // Mode d'emploi : Renvoie la position de la forme suivante composant 
    //                 l'objet complexe.
    // 
    // Contrat :
    //


protected:
//----------------------------------------------------- Attributs protégés
	
private:
//------------------------------------------------------- Attributs privés
    Dessin *dessin;
    Historique *histo;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Commande>

#endif // COMMANDE_H
