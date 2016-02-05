/*************************************************************************
                    ObjetSimple  -  Segments, rectangles et polygones
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//---------- Interface de la classe <ObjetSimple> (fichier ObjetSimple) --
#ifndef OBJETSIMPLE_H
#define OBJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Objet.h"
#include "Point.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Classe héritant d’objet, à laquelle s’ajoute la gestion d’une liste de
// Points liés à l’objet.
// De cette classe dépendent Polygone, Rectangle et Segment.
//------------------------------------------------------------------------

class ObjetSimple : public Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contient ( const Point & p ) const = 0;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    void Deplacer ( const Point & p );
    // Mode d'emploi :
    // Déplace l’objet selon le vecteur correspondant à p.
    // Contrat :
    // -

    void AddPoint (const Point & p);
    // Mode d'emploi :
    // Ajoute le point à l'objet.
    // Contrat :
    // Cette methode ne vérifie pas la convexité d’un Polygone, ou le
    // dépassement du nombre de points pour un Rectangle ou un Segment
    // (2 points). Ces vérifications sont à la charge de l’utilisateur.

//------------------------------------------------- Surcharge d'opérateurs
    ObjetSimple & operator = ( const ObjetSimple & unObjetSimple );
    // Contrat :
    // Copie l’objet, attribut par attribut.

//-------------------------------------------- Constructeurs - destructeur
    ObjetSimple ( const ObjetSimple & unObjetSimple );
    // Contrat :
    // Copie l’objet en utilisant la surcharge d’operateur =.

    ObjetSimple ( const string & nom );
    // Mode d'emploi :
    // Constructeur utilisé avec la methode addPoint.
    // Contrat :
    // -

    ObjetSimple ( const vector<Point> & desPoints,
                  const string & nom = "");
    // Mode d'emploi :
    // Constructeur utilisé pour les polygones convexe.
    // Contrat :
    // Crée un objet simple à partir d’une liste de points, en faisant
    // appel au constructeur d’Objet pour le nom.

    ObjetSimple ( const string & nom,
                  const Point & p1,
                  const Point & p2);
    // Mode d'emploi :
    // Constructeur utilisé pour les segments et rectangles.
    // Contrat :
    // Crée un objet simple à partir de deux points, en faisant appel au
    // constructeur d’Objet pour le nom.

    virtual ~ObjetSimple ( );
    // Contrat :
    // Affiche les appels au destructeur de ObjetSimple.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    // liste de Points définissant l’objet.
    std::vector<Point> points;

};

#endif // OBJETSIMPLE_H
