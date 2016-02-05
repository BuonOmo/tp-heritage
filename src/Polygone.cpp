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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Polygone.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Polygone::Contient ( const Point & p ) const
// Algorithme :
// Calcul le produit vectoriel entre les vecteurs constitués par deux
// points consecutifs et le premier de ces points avec p. Si le signe de
// ce produit vectoriel est constant alors p est contenu dans le polygone.
{
#ifdef MAP
    cout << "#Appel à la méthode Contient de <Polygone>" << endl;
#endif
    unsigned int it = 0;
    // Recherche d’une valeur initiale non nulle pour commencer le calcul.
    // Si tout les points d’un polygone sont identiques cela peut causer
    // une erreur.
    int val;
    val = (points.back() - p)^(points.front() - points.back());
    for (;val == 0;val = (points[it] - p)^(points[it+1] - points[it]),it++ )
    {
        // atteinte du maximum
        if (it>=points.size()-2)
        {
            return true;
        }
    }
    int firstVal;
    firstVal = val;
    // Comparaison des signes
    for (val = (points[it] - p)^(points[it+1] - points[it]) ;
         it < points.size()-1 ;
         it++,val = (points[it] - p)^(points[it+1] - points[it]) )
    {
        if (val*firstVal<0)
        {
            return false;
        }
    }
    return true;
} //----- Fin de Contient

Objet * Polygone::Copier ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode Copier de <Polygone>" << endl;
#endif
    return new Polygone(*this);
} //----- Fin de Copier

bool Polygone::EstConvexe ( const std::vector<Point> & pts )
// Algorithme :
// Effectue les produits vectoriels deux à deux de chaque cotés (orientés)
// du polygone. Si il y a changement de signe entre deux produits
// vectoriels successifs alors le Polygone crée par ces points ne sera pas
// convexe.
{
#ifdef MAP
    cout << "#Appel à la méthode EstConvexe de <Polygone>" << endl;
#endif
    Point precedent = pts.back();
    Point anteprecedent = pts[pts.size()-2];
    Point v1, v2;
    float vect = 0;
    float vectprec = vect;
    for (const Point p : pts)
    {
        v1 = p-precedent;
        v2 = precedent - anteprecedent;
        vect = v1^v2;
#ifdef MAP
    cout << "#vect : "<<vect << endl;
#endif
        if (vect*vectprec < 0)
        {
            return false;
        }
        anteprecedent = precedent;
        precedent = p;
        vectprec = vect;
    }
    return true;
} //----- Fin de EstConvexe

string Polygone::ToString ( ) const
{
#ifdef MAP
    cout << "#Appel à la méthode ToString de <Polygone>" << endl;
#endif
    string toReturn = "PC "+nom + " " + to_string(points.size());
    for (Point p : points)
    {
        toReturn+=" "+p.ToString();
    }
    return toReturn;
} //----- Fin de ToString

//-------------------------------------------- Constructeurs - destructeur
Polygone::Polygone ( const Polygone & unPolygone )
    : ObjetSimple(unPolygone)
{
#ifdef MAP
    cout << "#Appel au constructeur de copie de <Polygone>" << endl;
#endif
} //----- Fin de Polygone (constructeur de copie)

Polygone::Polygone ( const string & nom )
    : ObjetSimple(nom)
{
#ifdef MAP
    cout << "#Appel au constructeur de <Polygone>" << endl;
#endif
} //----- Fin de Polygone (string nom)


Polygone::Polygone ( const std::vector<Point> & listePoints,
                     const string & nom )
                     : ObjetSimple(listePoints, nom)
{
#ifdef MAP
    cout << "#Appel au constructeur de <Polygone>" << endl;
#endif
} //----- Fin de Polygone


Polygone::~Polygone ( )
{
#ifdef MAP
    cout << "#Appel au destructeur de <Polygone>" << endl;
#endif
} //----- Fin de ~Polygone
