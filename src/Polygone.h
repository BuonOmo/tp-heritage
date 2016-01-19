
    /*************************************************************************
                               Polygone  -  description
                                 -------------------
        début                : 19/1/2016
        copyright            : (C) 2016 par Pierre et Ulysse
    *************************************************************************/

    //-------------- Interface de la classe <Polygone> (fichier Polygone) --------------
    #if ! defined ( POLYGONE_H )
    #define POLYGONE_H

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Polygone>
    //
    //
    //------------------------------------------------------------------------

    class Polygone : public ObjetSimple
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste de paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs
        Polygone & operator = ( const Polygone & unPolygone );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Polygone ( const Polygone & unPolygone );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Polygone ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Polygone ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    private:
    //------------------------------------------------------- Méthodes privées

    protected:
    //----------------------------------------------------- Attributs protégés

    private:
    //------------------------------------------------------- Attributs privés

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Polygone>

    #endif // POLYGONE_H
