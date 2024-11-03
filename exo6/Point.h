#ifndef Point_h
#define Point_h

class Point{
private:
    float x;
    float y;

public:
    Point(float x, float y);

    void deplacer(float dx, float dy);
    void affiche()const;

};

#endif
