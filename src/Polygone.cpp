/*************************************************************************
                                Polygone
                             -------------------
    début                : 19/1/2016
    copyright            : (C) 2016 par Pierre et Ulysse
*************************************************************************/

//-------------- Réalisation de la classe <Polygone> (fichier Polygone) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Polygone.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Polygone::Contient ( Point p ) const
// Algorithme :
// Calcul le produit vectoriel entre les vecteurs constitués par deux
// points consecutifs et le premier de ces points avec p. Si le signe de
// ce produit vectoriel est constant alors p est contenu dans le polygone.
{
#ifdef MAP
    cout << "Appel à la méthode Contient de <Polygone>" << endl;
#endif
    unsigned int it = 0;
    // Recherche d’une valeur initiale non nulle pour commencer le calcul.
    // Si tout les points d’un polygone sont identiques cela peut causé une
    // erreure.
    int val;
    val = (points.back() - p)^(points.front() - points.back());
    for (;val != 0;val = (points[it] - p)^(points[it+1] - points[it]),it++ )
    {
        // atteinte du maximum
        // TODO optimisable en sortant ceci de la boucle
        if (it>=points.size()-2)
        {
            return true;
        }
    }
    bool signe;
    signe = val > 0 ? true : false;

    // Comparaison des signes
    for (val = (points[it] - p)^(points[it+1] - points[it]) ;
         it < points.size()-1 ;
         val = (points[it] - p)^(points[it+1] - points[it]),it++ )
    {
        if (val !=0)
        {
            if ((val > 0 && !signe) || (val < 0 && signe))
            {
                return false;
            }
        }
    }
    return true;
} //----- Fin de Contient

bool Polygone::EstConvexe ( std::vector<Point> & pts )
{
#ifdef MAP
    cout << "Appel à la méthode EstConvexe de <Polygone>" << endl;
#endif
    Point precedent = pts.back();
    Point anteprecedent = pts[pts.size()-2];
    Point v1, v2;
    float sinus = 0;
    float sinusprec = sinus;
    float somme = 0;
    for (Point p : pts)
    {
        v1 = p-precedent;
        v2 = precedent - anteprecedent;
        sinus = (float)(v1^v2) / (float)(sqrt(v1*v1) * sqrt(v2*v2));
#ifdef MAP
    cout << "#sinus : "<<sinus << endl;
#endif
        if ((sinus >= 0 && sinusprec < 0)||(sinus <= 0 && sinusprec > 0))
        {
            return false;
        }
        somme+= sinus;
        anteprecedent = precedent;
        precedent = p;
        sinusprec = sinus;
    }
#ifdef MAP
    cout << "#somme   : "<<somme << endl;
    cout << "#somme^2 : "<<somme*somme << endl;
    cout << "#pi^2 : "<<3.14*3.14 << endl;

#endif
    return !(somme*somme >= 3.14*3.14);
} //----- Fin de EstConvexe

string Polygone::ToString ( ) const
{
#ifdef MAP
    cout << "Appel à la méthode ToString de <Polygone>" << endl;
#endif
    string toReturn = "PC "+nom;
    for (Point p : points)
    {
        toReturn+=" "+p.ToString();
    }
    return toReturn;
} //----- Fin de ToString

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Polygone::Polygone ( const Polygone & unPolygone )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polygone>" << endl;
#endif
} //----- Fin de Polygone (constructeur de copie)


Polygone::Polygone ( const std::vector<Point> & listePoints,
                     const string & description,
                     const string & nom )
                     : ObjetSimple(listePoints, description, nom)
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
