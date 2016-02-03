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
    bool execute (const string commande, bool undo = false);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void executeCommande (const string commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void executeDescription (const string commande);
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
