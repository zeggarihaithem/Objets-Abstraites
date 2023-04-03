#ifndef OBJETABST_HPP
#define OBJETABST_HPP

#include<string>
#include<vector>
#include<iostream>
class ObjetAtomique;

using namespace std;


class ObjetAbst{
    private:
        static vector<pair<ObjetAtomique*, int*> > initializeRessources();
        static void decrementRessources();
        static void incrementRessources();
        static vector<int> getFreq();
    protected:
        const string nom;
        string commentaire;
        static const vector<pair<ObjetAtomique*,int*> > objetAtomiqueDisponible;
    public:
        ObjetAbst(string _nom);
        ObjetAbst(const ObjetAbst &objetAbst);
        virtual ~ObjetAbst();
        string getNom();
        string getComment();
        void setComment(string commentaire);
        static vector<string> getAllNames();
        static void testObjetAbst();
        static ObjetAtomique* forge(string nom);
        static ObjetAtomique* forge(const ObjetAtomique *ptr_objetAtomique);
        static ObjetAtomique* forge(const ObjetAtomique &objetAtomique);
};
#endif

