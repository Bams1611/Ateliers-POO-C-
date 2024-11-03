#include <iostream>
#include "Headers/Point.h"

Point::Point(float x, float y): x(x), y(y){}

void Point::deplacer(float dx, float dy){
    x+=dx;
    y+=dy;
}

void afficher() const{
     cout << "coordonnees:("<<x<<","<<y<<")"<<endl;
}
