#include "ObjetAtomique.hpp"

ObjetAtomique::ObjetAtomique(string nom):ObjetAbst(nom){}
ObjetAtomique::ObjetAtomique(const ObjetAtomique &objetAtomique): ObjetAbst(objetAtomique){}
ObjetAtomique::~ObjetAtomique(){
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       if(this == ObjetAbst::objetAtomiqueDisponible[i].first){
           *(ObjetAbst::objetAtomiqueDisponible[i].second)+=1;  
            return; 
       }
    }
}