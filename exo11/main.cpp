#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Traitement {
private:
    vector<int> entiers;

public:
    void Initialise();
    void show(int index = 0) const;
    friend double moyenne(const Traitement& t);
    friend double mediane(const Traitement& t);
};

void Traitement::Initialise() {
    int nombre;
    while (entiers.size() < 15) {
        cout << "Entrez un entier pair non nul : ";
        cin >> nombre;
        if (cin.fail() || nombre == 0 || nombre % 2 != 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valeur invalide. Veuillez réessayer." << endl;
        } else {
            entiers.push_back(nombre);
        }
    }
}

void Traitement::show(int index) const {
    if (index < entiers.size()) {
        cout << entiers[index] << " ";
        show(index + 1);
    }
}

double moyenne(const Traitement& t) {
    double somme = 0;
    for (int val : t.entiers) {
        somme += val;
    }
    return somme / t.entiers.size();
}

double mediane(const Traitement& t) {
    if (t.entiers.empty()) return 0.0;
    vector<int> copie = t.entiers;
    sort(copie.begin(), copie.end());
    int n = copie.size();
    if (n % 2 == 0) {
        return (copie[n / 2 - 1] + copie[n / 2]) / 2.0;
    } else {
        return copie[n / 2];
    }
}

int main() {
    Traitement traitement;
    traitement.Initialise();
    cout << "Les entiers saisis sont : ";
    traitement.show();
    cout << endl;0

    cout << "Moyenne : " << moyenne(traitement) << endl;
    cout << "Médiane : " << mediane(traitement) << endl;

    return 0;
}
