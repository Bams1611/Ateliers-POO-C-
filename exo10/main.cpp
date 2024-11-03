#include <iostream>
#include <string>

using namespace std;

int main() {
    string dateHeure;
    cout << "Entrez la date et l'heure sous la forme JJMMAAAAHHMM : ";
    cin >> dateHeure;

    if (dateHeure.length() != 12) {
        cout << "Format de date/heure invalide." << endl;
        return 1;
    }

    string jour = dateHeure.substr(0, 2);
    string mois = dateHeure.substr(2, 2);
    string annee = dateHeure.substr(4, 4);
    string heure = dateHeure.substr(8, 2);
    string minute = dateHeure.substr(10, 2);

    cout << "Date : " << jour << "/" << mois << "/" << annee << endl;
    cout << "Heure : " << heure << ":" << minute << endl;

    return 0;
}
