#include "ObjetAbst.hpp"
#include "ObjetAtomique.hpp"
#include <vector>
ObjetAbst::ObjetAbst(string _nom):nom(_nom){
    this->commentaire = " ";
}
ObjetAbst::ObjetAbst(const ObjetAbst &objetAbst):nom(objetAbst.nom){
    this->commentaire = objetAbst.commentaire;
}
ObjetAbst::~ObjetAbst(){
}
string ObjetAbst::getNom(){
    return this->nom;
}
string ObjetAbst::getComment(){
    return this->commentaire;
}
void ObjetAbst::setComment(string commentaire){
    this->commentaire = commentaire;
}
vector<string> ObjetAbst::getAllNames(){
    vector<string> allNames;
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       allNames.push_back((ObjetAbst::objetAtomiqueDisponible[i].first)->getNom());
    }
    return allNames;     
}
vector<pair<ObjetAtomique*, int*> > ObjetAbst::initializeRessources(){
    ObjetAtomique *a = new ObjetAtomique("A");
    ObjetAtomique *b = new ObjetAtomique("B");
    ObjetAtomique *c = new ObjetAtomique("C");
    ObjetAtomique *d = new ObjetAtomique("D");
    int *ptr_freqA = new int(2);
    int *ptr_freqB = new int(25);
    int *ptr_freqC = new int(50);
    int *ptr_freqD = new int(100);
    return {
        make_pair(a,ptr_freqA),
        make_pair(b,ptr_freqB),
        make_pair(c,ptr_freqC),
        make_pair(d,ptr_freqD)
    };
}
void ObjetAbst::decrementRessources(){
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       *(ObjetAbst::objetAtomiqueDisponible[i].second)-=1;
    }
}
void ObjetAbst::incrementRessources(){
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       *(ObjetAbst::objetAtomiqueDisponible[i].second)+=1;
    }
}
vector<int> ObjetAbst::getFreq(){
    vector<int> freq;
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       freq.push_back(*(ObjetAbst::objetAtomiqueDisponible[i].second));
    }
    return freq;
}
ObjetAtomique* ObjetAbst::forge(string nom){
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       int freq = *(ObjetAbst::objetAtomiqueDisponible[i].second);
       if((ObjetAbst::objetAtomiqueDisponible[i].first)->nom == nom){
           if(freq == 0) return nullptr;
           *(ObjetAbst::objetAtomiqueDisponible[i].second)-=1;
           return ObjetAbst::objetAtomiqueDisponible[i].first;
           //return new ObjetAtomique(nom);
       }
    }
    return nullptr;
}
ObjetAtomique* ObjetAbst::forge(const ObjetAtomique * ptr_objetAtomique){
    //ptr_objetAtomique.setComment("testConstant");
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       int freq = *(ObjetAbst::objetAtomiqueDisponible[i].second);
       if(ObjetAbst::objetAtomiqueDisponible[i].first == ptr_objetAtomique){
           if(freq == 0) return nullptr;
           *(ObjetAbst::objetAtomiqueDisponible[i].second)-=1;
           return ObjetAbst::objetAtomiqueDisponible[i].first;
           //return new ObjetAtomique( ptr_objetAtomique->nom);
       }
    }
    return nullptr;
}
ObjetAtomique* ObjetAbst::forge(const ObjetAtomique &objetAtomique){
    //objetAtomique.setComment("testConstant");
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       int freq = *(ObjetAbst::objetAtomiqueDisponible[i].second);
       if((ObjetAbst::objetAtomiqueDisponible[i].first)->getNom() == objetAtomique.nom){
           if(freq == 0) return nullptr;
           *(ObjetAbst::objetAtomiqueDisponible[i].second)-=1;
           return ObjetAbst::objetAtomiqueDisponible[i].first;
           //return new ObjetAtomique(objetAtomique.nom);
       }
    }
    return nullptr;
}
// Construisez ici l'inventaire global des pièces disponibles,
// avec un vecteur contenant les 4 objets Atomiques, A,B,C,D ayant respectivement des frequences 2,25,50,100
const vector<pair <ObjetAtomique*,int*> > ObjetAbst::objetAtomiqueDisponible = ObjetAbst::initializeRessources();
void ObjetAbst::testObjetAbst(){
    // ------------ Test 2 ---------
    // montrez ici qu'on ne peut plus ajouter d'objetAtomique à l'inventaire initial 
    // c.a d. essayez d'en ajoutez dans une ligne que vous laisserez en commentaire
    //ObjetAtomique* e = new ObjetAtomique("E", "");
    //int *freqE = new int(1);
    //ObjetAbst::objetAtomiqueDisponible.push_back(make_pair(e, freqE));
    // Expliquez en qqs phrases, et mettez en évidence en MAJUSCULE ce qui dans le type a empéché l'action de se faire
    //
    //
    // ------------ Test 3 ---------
    // montrez ici comment réduire le stock d'une unité pour toutes les pièces disponibles
    ObjetAbst::decrementRessources();
    // récupérez ensuite séparément le vecteur des fréquences 
    vector<int> v_freq;
    // a completer
    v_freq = ObjetAbst::getFreq();
    if (v_freq==vector<int>{1,24,49,99}) cout << "- ok decroissance frequence" << endl;
    else cout << "PB DECROISSANCE FREQUENCE" << endl;
    // puis remettez ici les fréquences en l'état
    ObjetAbst::incrementRessources();
    // ------------ Test 4 -----------

    // vous allez tenter ici de modifier tous les noms et commentaires en leur ajoutant "_mod"
    // ca doit être impossible pour les noms, mais possible pour les commentaires
    // n'affichez rien, et laissez en commentaire la ligne qui échoue
    // nous la testerons en la décommantant
    // code :
    for (unsigned int i=0; i < ObjetAbst::objetAtomiqueDisponible.size(); i++){
       //(ObjetAbst::objetAtomiqueDisponible[i].first)->nom="_mod";
       (ObjetAbst::objetAtomiqueDisponible[i].first)->commentaire="_mod";
    }
    // Expliquez ici en formant une phrase compréhensible, ce qui dans les types 
    // permet de répondre précisément à la spécification précédente
    // (utilisez des majuscules pour faire ressortir les mots clés significatifs) 
 
}



