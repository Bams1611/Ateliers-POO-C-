#include <iostream>

using namespace std;

struct Element {
    int valeur;
    Element* suivant;
};

class Liste {
private:
    Element* premier;
public:
    Liste() : premier(nullptr) {}
    ~Liste();

    void ajouterDebut(int valeur);
    void supprimerDebut();
    void afficher() const;
};

Liste::~Liste() {
    while (premier) {
        supprimerDebut();
    }
}

void Liste::ajouterDebut(int valeur) {
    Element* nouveau = new Element;
    nouveau->valeur = valeur;
    nouveau->suivant = premier;
    premier = nouveau;
}

void Liste::supprimerDebut() {
    if (premier) {
        Element* aSupprimer = premier;
        premier = premier->suivant;
        delete aSupprimer;
    }
}

void Liste::afficher() const {
    Element* actuel = premier;
    while (actuel) {
        cout << actuel->valeur << " ";
        actuel = actuel->suivant;
    }
    cout << endl;
}


int main() {
    Liste liste;
    liste.ajouterDebut(13);
    liste.ajouterDebut(29);
    liste.ajouterDebut(70);
    liste.afficher();

    liste.supprimerDebut();
    liste.afficher();

    return 0;
}

