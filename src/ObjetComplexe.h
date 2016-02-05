/*************************************************************************
                        ObjetComplexe  -  liste d’objets
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//------ Interface de la classe <ObjetComplexe> (fichier ObjetComplexe) --
#ifndef OBJETCOMPLEXE_H
#define OBJETCOMPLEXE_H

//--------------------------------------------------- Interfaces utilisées
#include "Objet.h"
#include <vector>

//------------------------------------------------------------------------
// La classe ObjetComplexe hérite de Objet et permet de gérer des
// ensembles ou collections d’objet de type Union ou Intersection.
//------------------------------------------------------------------------

class ObjetComplexe : public Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contient ( const Point & p ) const = 0;
    // Contrat :
    // Renvoi vrai si p est contenu dans l’objet.

    void Deplacer ( const Point & p );
    // Mode d'emploi :
    // p correspond à un vecteur de déplacement et non un point.
    //
    // Contrat :
    // Déplace l’objet selon le vecteur correspondant à p.

    void Renommer ( const string & nouveauNom );
    // Mode d’emploi :
    // Permet de renommer un objet (utile pour les objets complexes).
    // Contrat :
    // Attribue nouveauNom à la variable nom, et nouveauNom+nom aux sous
    // objets.

    void AddObjet (Objet * o);
    // Mode d’emploi :
    // Permet d'ajouter un objet à l'objet complexe.
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    ObjetComplexe & operator = ( const ObjetComplexe & unObjetComplexe );
    // Contrat :
    // Copie l’objet, attribut par attribut. Pour l’attribut objets, copie
    // un a un chaque pointeur en construisant un nouvel objet avec la
    // methode Copier () de Objet.


//-------------------------------------------- Constructeurs - destructeur
    ObjetComplexe ( const ObjetComplexe & unObjetComplexe );
    // Contrat :
    // Copie l’objet en utilisant la surcharge d’operateur =.

    ObjetComplexe ( const string & unNom,
                    const std::vector<Objet *> &desObjets);
    // Contrat :
    // Crée un objet complexe à partir d’une liste d’objets, en faisant
    // appel au constructeur d’Objet pour le nom.

    virtual ~ObjetComplexe ( );
    // Contrat :
    // Détruit tous les objets de la liste du même nom un à un.

protected:
//----------------------------------------------------- Attributs protégés
    // Liste d’objets contenu par l’ensemble.
    std::vector<Objet *> objets;

};

#endif // OBJETCOMPLEXE_H
