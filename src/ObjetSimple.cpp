/*************************************************************************
                    ObjetSimple  -  Segments, rectangles et polygones
                             -------------------
    début                : 18/01/2016
    copyright            : (C) 2016 par pierre et ulysse
*************************************************************************/

//-------- Réalisation de la classe <ObjetSimple> (fichier ObjetSimple) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "ObjetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ObjetSimple::Deplacer ( const Point & p )
{
#ifdef MAP
    cout << "#Appel à la méthode Deplacer de <ObjetSimple>" << endl;
#endif
    for (size_t i = 0; i < points.size(); ++i)
    {
        points[i] = points[i] + p;

    }
} //----- Fin de Deplacer

void ObjetSimple::AddPoint(const Point & p)
{
#ifdef MAP
    cout << "#Appel à la méthode AddPoint de <ObjetSimple>" << endl;
#endif
    points.push_back(p);
} //----- Fin de Deplacer

//------------------------------------------------- Surcharge d'opérateurs
ObjetSimple & ObjetSimple::operator = ( const ObjetSimple & unObjetSimple)
{
    if (this != &unObjetSimple)
    {
        points = unObjetSimple.points;
        nom = unObjetSimple.nom;
        // TODO gerer l’appel à l’operateur = de la classe mere
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ObjetSimple::ObjetSimple ( const ObjetSimple & unObjetSimple )
{
#ifdef MAP
    cout << "#Appel au constructeur de copie de <ObjetSimple>" << endl;
#endif
    *this = unObjetSimple;
} //----- Fin de ObjetSimple (constructeur de copie)


ObjetSimple::ObjetSimple ( const vector<Point> & desPoints,
                           const string & nom )
    : Objet(nom), points (desPoints)
{
#ifdef MAP
    cout << "#Appel au constructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ObjetSimple

ObjetSimple::ObjetSimple ( const string & nom ) : Objet(nom)
{
#ifdef MAP
    cout << "#Appel au constructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ObjetSimple

ObjetSimple::ObjetSimple ( const string & nom,
                           const Point & p1,
                           const Point & p2)
    : Objet(nom)
{
#ifdef MAP
    cout << "#Appel au constructeur de <ObjetSimple>" << endl;
#endif
    points.push_back(p1);
    points.push_back(p2);
} //----- Fin de ObjetSimple

ObjetSimple::~ObjetSimple ( )
{
#ifdef MAP
    cout << "#Appel au destructeur de <ObjetSimple>" << endl;
#endif
} //----- Fin de ~ObjetSimple
