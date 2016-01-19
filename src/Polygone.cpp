
    /*************************************************************************
                               Polygone  -  description
                                 -------------------
        début                : 19/1/2016
        copyright            : (C) 2016 par Pierre et Ulysse
    *************************************************************************/

    //---------- Réalisation de la classe <Polygone> (fichier Polygone) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "Polygone.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Polygone::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    Polygone & Polygone::operator = ( const Polygone & unPolygone )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    Polygone::Polygone ( const Polygone & unPolygone )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Polygone>" << endl;
    #endif
    } //----- Fin de Polygone (constructeur de copie)


    Polygone::Polygone ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Polygone>" << endl;
    #endif
    } //----- Fin de Polygone


    Polygone::~Polygone ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Polygone>" << endl;
    #endif
    } //----- Fin de ~Polygone


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    