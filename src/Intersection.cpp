/*************************************************************************
                                Intersection
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-- Réalisation de la classe <Intersection> (fichier Intersection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Intersection.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Intersection::Contient (const Point & p) const
// Algorithme :
// Recherche si un des objet de objets contient p. Si c’est le cas un
// booleen (premier) devient vrai, et si un autre objet est contenu, la
// méthode renvoi vrai.
{
#ifdef MAP
    cout << "#Appel à la méthode Contient de <Intersection>" << endl;
#endif
    bool premier (false);
    for (Objet * obj : objets )
    {
        if ( obj -> Contient(p) )
        {
            if (premier)
            {
                return true;
            }
            premier = true;
        }
    }
    return false;
} //----- Fin de Contient

Objet * Intersection::Copier ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode Copier de <Intersection>" << endl;
#endif
    return new Intersection (*this);
} //----- Fin de Copier

string Intersection::ToString ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode ToString de <Intersection>" << endl;
#endif
    string toReturn = "OI "+nom;
    toReturn+=" " + to_string(objets.size());
    for (Objet * o : objets)
    {
        toReturn+= " " + o -> ToString();
    }
    return toReturn;
} //----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Intersection::Intersection ( const Intersection & unIntersection )
    : ObjetComplexe(unIntersection)
{
#ifdef MAP
    cout << "#Appel au constructeur de copie de <Intersection>" << endl;
#endif
} //----- Fin de Intersection (constructeur de copie)


Intersection::Intersection ( const string & unNom ,
                             const std::vector<Objet *> & desObjets)
    : ObjetComplexe(unNom, desObjets)
{
#ifdef MAP
    cout << "#Appel au constructeur de <Intersection>" << endl;
#endif
} //----- Fin de Intersection


Intersection::~Intersection ( )
{
#ifdef MAP
    cout << "#Appel au destructeur de <Intersection>" << endl;
#endif

} //----- Fin de ~Intersection
