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
    void add (const string commande);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void undo ();
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
    std::deque<string> commandes;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Historique>

#endif // HISTORIQUE_H
