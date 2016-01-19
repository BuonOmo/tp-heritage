
    /*************************************************************************
                               Segment  -  description
                                 -------------------
        début                : 19/1/2016
        copyright            : (C) 2016 par Pierre et Ulysse
    *************************************************************************/

    //---------- Réalisation de la classe <Segment> (fichier Segment) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "Segment.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Segment::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    Segment & Segment::operator = ( const Segment & unSegment )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    Segment::Segment ( const Segment & unSegment )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Segment>" << endl;
    #endif
    } //----- Fin de Segment (constructeur de copie)


    Segment::Segment ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Segment>" << endl;
    #endif
    } //----- Fin de Segment


    Segment::~Segment ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Segment>" << endl;
    #endif
    } //----- Fin de ~Segment


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    