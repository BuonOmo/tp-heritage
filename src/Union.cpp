/*************************************************************************
                                    Union
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Réalisation de la classe <Union> (fichier Union.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Union.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Union::Contient (const Point & p) const
// Algorithme :
// Parcours objets et renvoi vrai si un des objets contient p.
{
#ifdef MAP
    cout << "#Appel à la méthode Contient de <Union>" << endl;
#endif
    for (Objet * obj : objets )
    {
        if ( obj -> Contient(p) )
        {
            return true;
        }
    }
    return false;
} //----- Fin de Contient

Objet * Union::Copier ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode Copier de <Union>" << endl;
#endif
    return new Union (*this);
} //----- Fin de Copier

string Union::ToString ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode ToString de <Union>" << endl;
#endif
    string toReturn = "OR "+nom;
    toReturn+=" " + to_string(objets.size());
    for (Objet * o : objets)
    {
        toReturn+= " " + o -> ToString();
    }
    return toReturn;
} //----- Fin de ToString

//-------------------------------------------- Constructeurs - destructeur
Union::Union ( const Union & unUnion ) : ObjetComplexe(unUnion)
{
#ifdef MAP
    cout << "#Appel au constructeur de copie de <Union>" << endl;
#endif
} //----- Fin de Union (constructeur de copie)


Union::Union ( const string & unNom ,
               const std::vector<Objet *> & desObjets)
    : ObjetComplexe(unNom, desObjets)
{
#ifdef MAP
    cout << "#Appel au constructeur de <Union>" << endl;
#endif
} //----- Fin de Union


Union::~Union ( )
{
#ifdef MAP
    cout << "#Appel au destructeur de <Union>" << endl;
#endif
} //----- Fin de ~Union
