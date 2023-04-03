#include "ObjetCompose.hpp"
ObjetCompose::ObjetCompose(string nom):ObjetAbst(nom){}
ObjetCompose::~ObjetCompose(){
    for(unsigned int i = 0; i < listObjetAtomique.size(); i++){
       delete listObjetAtomique[i];
    }
}
void ObjetCompose::operator[] (ObjetAtomique *& objetAtomique){
    listObjetAtomique.push_back(objetAtomique);
    objetAtomique = nullptr;
}
void ObjetCompose::afficherComposantes(){
    for(unsigned int i = 0; i < listObjetAtomique.size(); i++){
       cout<<i+1<<" - "<< listObjetAtomique[i]->getNom()<< endl;
    }
}