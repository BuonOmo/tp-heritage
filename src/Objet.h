/*************************************************************************
                                    Objet
                             -------------------
    début                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//---------------- Interface de la classe <Objet> (fichier Objet.h) ------
#ifndef OBJET_H
#define OBJET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Point.h"

//------------------------------------------------------------------------
// Classe abstraite permettant la gestion d’objet. Seul le nom est
// pris en compte ici.
//------------------------------------------------------------------------

class Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Deplacer ( const Point & p ) = 0;
    // Mode d'emploi :
    // p correspond à un vecteur de déplacement et non un point.
    // Contrat :
    // Déplace l’objet selon le vecteur correspondant à p.

    virtual bool Contient ( const Point & p ) const = 0;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    virtual Objet * Copier ( ) const = 0;
    // Contrat :
    // Renvoi un pointeur vers une copie de l’objet.

    string GetNom ( ) const;
    // Contrat :
    // Renvoi le nom de l’objet.

    virtual void Renommer ( const string & nouveauNom );
    // Mode d’emploi :
    // Permet de renommer un objet (utile pour les objets complexes).
    // Contrat :
    // Attribue nouveauNom à la variable nom.

    virtual string ToString () const = 0;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.

//------------------------------------------------- Surcharge d'opérateurs
    Objet & operator = ( const Objet & unObjet );



//-------------------------------------------- Constructeurs - destructeur
    Objet ( const Objet & unObjet );
    // Contrat :
    // Copie l’objet en utilisant la surcharge d’operateur =.

    Objet ( const string & unNom = "" );
    // Contrat :
    // Initie le nom d’un objet.

    virtual ~Objet ( );
    // Contrat :
    // -

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    //Nom de l’objet
    string nom;

private:
//------------------------------------------------------- Attributs privés
    //Deprecated
    int c;

};

#endif // OBJET_H
