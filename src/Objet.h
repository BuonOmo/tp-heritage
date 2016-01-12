/*************************************************************************
                                    Objet
                             -------------------
    d�but                : 12 janvier 2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//---------- Interface de la classe <Objet> (fichier Objet.h) ------
#ifndef ( OBJET_H )
#define OBJET_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Objet>
//
//
//------------------------------------------------------------------------

class Objet : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    Objet & operator = ( const Objet & unObjet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Objet ( const Objet & unObjet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Objet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Objet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Objet>

#endif // OBJET_H
