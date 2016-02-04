/*************************************************************************
                           Historique  -  gestion de la liste des commandes
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Interface de la classe <Historique> (fichier Historique.h) ----------
#ifndef HISTORIQUE_H
#define HISTORIQUE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>   
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Historique>
//
//
//------------------------------------------------------------------------

class Historique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void add (const vector<string> commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void addRedo (const vector<string> commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void viderRedo ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    vector<string> getCommandeUndo ();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    vector<string> getCommandeRedo ();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Historique ();
    // Mode d'emploi () :
    //
    // Contrat :
    //

    
    virtual ~Historique ( );
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
    //std::deque<string> commandes;
    std::deque<vector<string>> commandesUndo;
    std::deque<vector<string>> commandesRedo;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Historique>

#endif // HISTORIQUE_H
