#include <iostream>
#include "Headers/Point.h"

using namespace std;

int main()
{
    Point p(3.8, 4.7);

    cout << "Avant d�placement : ";
    p.affiche();

    p.deplace(2.0, -1.5);

    cout << "Apr�s d�placement : ";
    p.affiche();


    return 0;
}
