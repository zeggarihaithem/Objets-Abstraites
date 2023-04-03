#ifndef OBJETCOMPOSE_HPP
#define OBJETCOMPOSE_HPP
#include<vector>
#include <iostream>
#include "ObjetAbst.hpp"
#include "ObjetAtomique.hpp"
using namespace std;
class ObjetCompose: public ObjetAbst{
    private:
        vector<ObjetAtomique*> listObjetAtomique;
    public:
        ObjetCompose(string nom);
        ~ObjetCompose();
        void operator[] (ObjetAtomique *& objetAtomique);
        void afficherComposantes();    
};

#endif /* OBJETCOMPOSÉ_HPP */

