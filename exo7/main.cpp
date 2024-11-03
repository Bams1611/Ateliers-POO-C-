#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Pile {
private:
    vector<int> elements;

public:
    Pile();

    void push(int valeur);
    int pop();
    bool estVide() const;
};

Pile::Pile() {}


void Pile::push(int valeur) {
    elements.push_back(valeur);
}

int Pile::pop() {
    if (estVide()) {
        throw out_of_range("La pile est vide. Impossible de dépiler.");
    }
    int valeur = elements.back();
    elements.pop_back();
    return valeur;
}

bool Pile::estVide() const {
    return elements.empty();
}

int main() {
    Pile p1, p2;

    p1.push(6);
    p1.push(8);
    p1.push(11);

    p2.push(5);
    p2.push(17);
    p2.push(29);

    cout << "Dépilage de p1 : ";
    while (!p1.estVide()) {
        cout << p1.pop() << " "<<endl;
    }


    cout << "Dépilage de p2 : ";
    while (!p2.estVide()) {
        std::cout << p2.pop() << " "<<endl;
    }

    return 0;
}
