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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ObjetComplexe>
//
//
//------------------------------------------------------------------------

class ObjetComplexe : public Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    ObjetComplexe & operator = ( const ObjetComplexe & unObjetComplexe );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ObjetComplexe ( const ObjetComplexe & unObjetComplexe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ObjetComplexe ( const Objet &desObjets = new Objet(1), const string &aSous-Descriptions = new string (10) );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ObjetComplexe ( );
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
Objet * objets;
string * sous-descriptions;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <ObjetComplexe>

#endif // OBJETCOMPLEXE_H
