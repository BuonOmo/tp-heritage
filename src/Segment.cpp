/*************************************************************************
                                    Segment
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//------------ Réalisation de la classe <Segment> (fichier Segment.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Segment.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Segment::Contient ( const Point & p ) const
{
#ifdef MAP
    cout << "#Appel à la méthode Contient de <Segment>" << endl;
#endif
    return !( (p - points[0] ) ^ (points[1] - points[0] ) )
           &&
           p.XIn(points[0], points[1]);
} //----- Fin de Contient

Objet * Segment::Copier ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode Copier de <Segment>" << endl;
#endif
    return new Segment(*this);
} //----- Fin de Copier

string Segment::ToString ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode ToString de <Segment>" << endl;
#endif
    string toReturn = "S "+nom /*+ " 2"*/;
    for (Point p : points)
    {
        toReturn+=" "+p.ToString();
    }
    return toReturn;
} //----- Fin de ToString

//-------------------------------------------- Constructeurs - destructeur
Segment::Segment ( const Segment & unSegment ) : ObjetSimple(unSegment)
{
#ifdef MAP
    cout << "#Appel au constructeur de copie de <Segment>" << endl;
#endif
} //----- Fin de Segment (constructeur de copie)

Segment::Segment ( const string & nom ) : ObjetSimple(nom)
{
#ifdef MAP
    cout << "#Appel au constructeur de <Segment>" << endl;
#endif
} //----- Fin de Segment

Segment::Segment ( const string & unNom,
                   const Point & p1,
                   const Point & p2)
    : ObjetSimple( unNom, p1, p2 )
{

#ifdef MAP
    cout << "#Appel au constructeur de <Segment>" << endl;
#endif
} //----- Fin de Segment


Segment::~Segment ( )
{

#ifdef MAP
    cout << "#Appel au destructeur de <Segment>" << endl;
#endif
} //----- Fin de ~Segment
