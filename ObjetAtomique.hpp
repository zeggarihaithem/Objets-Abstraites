#ifndef OBJETATOMIQUE_HPP
#define OBJETATOMIQUE_HPP

#include "ObjetAbst.hpp"
using namespace std;
class ObjetAtomique: public ObjetAbst{
    friend ObjetAbst;
    private:
        ObjetAtomique(string nom);
        ObjetAtomique(const ObjetAtomique &objetAtomique);
    public:
        ~ObjetAtomique();    
};
#endif
