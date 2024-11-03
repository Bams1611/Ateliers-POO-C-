#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Fichier{
private:
    char* P;
    int longueur;
public:
    Fichier(): P(nullptr), longueur(0) {}
    ~Fichier(){
        delete[] P;
        cout<<"Destruction de l'objet Fichier et liberation de la memoire"<<endl;
    }

    void Creation(int taille);
    void Remplir();
    void Affiche() const;
};

void Fichier::Creation(int taille){
    if(P){
        delete[] P;
    }
    P= new char[taille];
    longueur=taille;
    cout<<"espace de "<<taille<<"alloue"<<endl;

}

void Fichier::Remplir(){
    if(!P){
        cerr<<" Erreur car la memoire n'a pas ete allouee!"<<endl;
        return;
    }
    srand(time(0));
    for(int i=0;i<longueur;i++){
        P[i]='A'+rand()% 26;
    }
    cout<<"la zone memoire a ete remplie arbitrairement"<<endl;
}

void Fichier::Affiche()const{
    if (!P) {
            cerr << "Erreur car la mémoire n'a pas été allouée." << endl;
            return;
        }
        for (int i = 0; i < longueur; ++i) {
            cout << P[i] << " ";
        }
        cout <<endl;
    }

int main(){
    Fichier* fichier = new Fichier;

    fichier->Creation(10);
    fichier->Remplir();
    fichier->Affiche();


    delete fichier;
    return 0;
}
