#include <iostream>
#include <math.h>

using namespace std;

class vecteur3d{
private:
    float x;
    float y;
    float z;

public:
    vecteur3d(float x=0, float y=0, float z=0):x(x), y(y), z(z){}

    void display()const;
    vecteur3d somme(const vecteur3d& v) const;
    float produitScalaire(const vecteur3d& v)const;
    bool coincide(const vecteur3d& v)const;
    float norme() const;
     static vecteur3d normax(const vecteur3d& v1, const vecteur3d& v2);
    static const vecteur3d* normaxAdresse(const vecteur3d& v1, const vecteur3d& v2);
     static const vecteur3d& normaxReference(const vecteur3d& v1, const vecteur3d& v2);
};

void vecteur3d::display()const{
    cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
}

vecteur3d vecteur3d::somme (const vecteur3d& v)const{
    return vecteur3d(x+v.x, y+v.y, z+v.z);
}

float vecteur3d::produitScalaire(const vecteur3d& v) const{
    return(x*v.x+y*v.y+z*v.z);
}
bool vecteur3d::coincide(const vecteur3d& v)const{
    return(x==v.x && y==v.y && z==v.z);
}
float vecteur3d::norme()const{
    return sqrt(x*x+y*y+z*z);
}

vecteur3d vecteur3d::normax(const vecteur3d& v1, const vecteur3d& v2) {
    return (v1.norme() >= v2.norme()) ? v1 : v2;
}

const vecteur3d* vecteur3d::normaxAdresse(const vecteur3d& v1, const vecteur3d& v2) {
    return (v1.norme() >= v2.norme()) ? &v1 : &v2;
}

const vecteur3d& vecteur3d::normaxReference(const vecteur3d& v1, const vecteur3d& v2) {
    return (v1.norme() >= v2.norme()) ? v1 : v2;
}
int main()
{
    return 0;
}
