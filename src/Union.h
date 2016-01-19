
    /*************************************************************************
                               Union  -  description
                                 -------------------
        début                : 19/1/2016
        copyright            : (C) 2016 par Pierre et Ulysse
    *************************************************************************/

    //-------------- Interface de la classe <Union> (fichier Union) --------------
    #if ! defined ( UNION_H )
    #define UNION_H

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Union>
    //
    //
    //------------------------------------------------------------------------

    class Union
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
        Union & operator = ( const Union & unUnion );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Union ( const Union & unUnion );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Union ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Union ( );
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

    //----------------------------------------- Types dépendants de <Union>

    #endif // UNION_H
    