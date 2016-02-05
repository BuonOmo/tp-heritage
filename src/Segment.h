/*************************************************************************
                                    Segment
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Interface de la classe <Segment> (fichier Segment.h) ----
#ifndef SEGMENT_H
#define SEGMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "ObjetSimple.h"
#include "Point.h"

//------------------------------------------------------------------------
// Classe permettant d’utiliser l’objet Segment :
// permet principalement de vérifier si un point est sur le segment et de
// deplacer le segment dans l’espace.
//------------------------------------------------------------------------

class Segment : public ObjetSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Contient (const Point & p) const;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    Objet * Copier ( ) const;
    // Contrat :
    // Renvoi un pointeur vers une copie de l’objet.

    string ToString () const;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.



//-------------------------------------------- Constructeurs - destructeur
    Segment ( const Segment & unSegment );
    // Contrat :
    // Constructeur de copie basé sur la surcharge d’operateur = de
    // ObjetSimple.

    Segment ( const string & nom = "" );
    // Mode d'emploi :
    // Constructeur par defaut, à utiliser avec la methode addPoint().
    // Contrat :
    // L’ajout de points ulterieure n’est pas vérifiée, c’est à la charge
    // de l’utilisateur d’en mettre deux. Il est recommandé d’instancié
    // un nom.

    Segment ( const string & unNom,
              const Point & p1,
              const Point & p2);
    // Contrat :
    // Constructeur prenant deux Points et appelant le constructeur
    // équivalent de ObjetSimple.

    virtual ~Segment ( );
    // Contrat :
    // Affiche les appels au destructeur de Segment.

};

#endif // SEGMENT_H
