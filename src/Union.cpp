
    /*************************************************************************
                               Union  -  description
                                 -------------------
        début                : 19/1/2016
        copyright            : (C) 2016 par Pierre et Ulysse
    *************************************************************************/

    //---------- Réalisation de la classe <Union> (fichier Union) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "Union.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Union::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    Union & Union::operator = ( const Union & unUnion )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    Union::Union ( const Union & unUnion )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Union>" << endl;
    #endif
    } //----- Fin de Union (constructeur de copie)


    Union::Union ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Union>" << endl;
    #endif
    } //----- Fin de Union


    Union::~Union ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Union>" << endl;
    #endif
    } //----- Fin de ~Union


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    