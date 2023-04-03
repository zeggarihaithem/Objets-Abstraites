#include "ObjetAbst.hpp"
#include "ObjetAtomique.hpp"
#include "ObjetCompose.hpp"
using namespace std;

int main(int argc, char** argv) {
    // Test 1 ---------- getAllNames
    string names="";
    for (string s:ObjetAbst::getAllNames()) names+=s;
    if (names=="ABCD") cout << "- ok names"<< endl; else cout << "PB NAMES" << endl;
    // appels aux test qui sont fait en local dans ObjetAbst
    ObjetAbst::testObjetAbst();
    
   // Test 5
    // On vérifie ici le fonctionnement de vos forge en procédant à 3 constructions de "A" 
    // et en s'assurant que la ressource s'est bien tarie (on n'en avait prévu que 2 au départ)
    // 
    ObjetAtomique *a0 = ObjetAbst::forge("A");
    a0->setComment("a0");
    ObjetAtomique *a1 = ObjetAbst::forge(a0);
    a1->setComment("a1");
    ObjetAtomique *a2 = ObjetAbst::forge(*a1);
    if (a2==nullptr) cout << "- ok forge : la ressource s'est tarie" << endl;
    else cout << "PB LA FORGE PRODUIT SANS RESPECTER LA LIMITE" << endl;
   
    // Test 6 
    // dans le code de ces deux dernières forges, vérifiez que l'argument que vous avez passé est typé afin de n'etre pas modifiable
    // pour cela écrivez y une ligne qui effectue un appel à setComment("testConstant") sur l'argument
    // laissez le en commentaire, puisqu'il devrait échouer.
    
    // Test 7
    // Vérifiez à présent les interdictions de copie et d'affectation en exhibant 2 lignes qui doivent echouer
    //ObjetAtomique a3 = *a0;
    //ObjetAtomique a4(*a0);
    // Expliquez aussi, clairement, comment vous avez restreint la construction.
    // En une phrase minimum, et en faisant ressortir en majuscule les choses importantes de votre code


    
    // Test 8
    // La destruction d'un ObjetAtomique doit restituer la ressource dans PiecesDisponibles
    // On vérifie cela ici en restituant a0, et reforgeant a2;
    delete a0;
    a0=nullptr; // simple précaution 
    a2=ObjetAbst::forge(*a1); // retourne un exemplaire
    if (a2!=nullptr) cout << "- ok le recyclage est passé (1/2)" << endl;
    else cout <<"PB AVEC LE RECYCLAGE 1" << endl;
    a2->setComment("a2 par recyclage de a0"); // qui doit être possible

    a0=ObjetAbst::forge(*a1);
    if (a0==nullptr) cout <<  "- ok : le recyclage est passé (2/2)" << endl;
    else cout << "PB avec le recyclage 2" << endl;
    // Expliquez ici en francais les une ou deux choses qu'il vous a fallu faire
        
    
    // -----------------------------------------------------------------
    // Test 9
    {// on ouvre un bloc dans ce test
        ObjetCompose ab{" a et b"};  // notre exemple à venir
        ObjetAtomique *b = ObjetAbst::forge("B"); // un composant
        ab[a1]; // ab va intégrer ce A
        ab[b]; // ab va intégrer ce B
        // et en même temps qu'ils aient été intégrés, on voudrait que a1 et b soient devenu null
        if ((a1==nullptr)) cout << "- ok fonction d'integration realisee (1/2)" << endl;
        else cout << "PB LES OBJETS ONT MAL ETE INTEGRES DANS AB (1/2)" << endl;
        // montrez nous ici le contenu de ab
        cout << "### affichage des composants contenus dans ab (on attend un A et un B) (2/2)" << endl; 
        // à faire
        ab.afficherComposantes();
    } // remarquez qu'à la sortie de ce bloc ab est detruit     
    // sa destruction doit restituer les ancien a1 et b
    // en particulier, arrivé ici on doit pouvoir forger un nouvel A
    a1=ObjetAbst::forge("A");
    if (a1!=nullptr){
        cout << "- ok la destruction de ab a libéré ses ressources " << endl;
    } else cout << "PB : LA DESTRUCTION DE AB N'A PAS LIBERE SES RESSOURCES" << endl;    

    return 0;
}

