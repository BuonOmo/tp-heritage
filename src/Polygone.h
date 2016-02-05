/*************************************************************************
                                Polygone
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Interface de la classe <Polygone> (fichier Polygone) ----
#ifndef POLYGONE_H
#define POLYGONE_H

//--------------------------------------------------- Interfaces utilisées
#include "ObjetSimple.h"
#include "Point.h"
#include <vector>

//------------------------------------------------------------------------
// Classe permettant d’utiliser l’objet Polygone :
// permet principalement de vérifier si un point est sur le polygone et de
// deplacer le polygone dans l’espace.
// Elle permet entre autre de verifier avant la création d’un polygone
// que celui-ci sera convexe.
//------------------------------------------------------------------------

class Polygone : public ObjetSimple
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

    static bool EstConvexe ( const std::vector<Point> & pts );
    // Contrat :
    // Renvoi vrai si la liste ordonnée de points donne un polygone
    // convexe.

    string ToString () const;
    // Contrat :
    // Renvoi la ligne de commande correspondant à la création de l’objet.

//-------------------------------------------- Constructeurs - destructeur
    Polygone ( const Polygone & unPolygone );
    // Contrat :
    // Constructeur de copie basé sur la surcharge d’operateur = de
    // ObjetSimple.

    Polygone ( const string & nom );
    // Mode d'emploi :
    // Constructeur par defaut, à utiliser avec la methode addPoint().
    // Contrat :
    // L’ajout de points ulterieure n’est pas vérifiée, c’est à la charge
    // de l’utilisateur de mettre une liste de points ordonnée et donnant
    // un polygone convexe (voir methode EstConvexe).
    // Il est recommandé d’instancier un nom.

    Polygone ( const std::vector<Point> & listePoints,
               const string & nom );
   // Contrat :
   // Constructeur prenant une liste de Points et appelant le constructeur
   // équivalent de ObjetSimple.

    virtual ~Polygone ( );
    // Contrat :
    // Affiche les appels au destructeur de Polygone.

};

#endif // POLYGONE_H
