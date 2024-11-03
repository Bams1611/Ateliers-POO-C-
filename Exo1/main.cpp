#include <iostream>
#include <stdexcept>
using namespace std;

class Complexe{
private:
    double Re;
    double Im;
public:
    Complexe(double Re=0, double Im=0): Re(Re), Im(Im){}
    Complexe operator+(const Complexe& other) const;
    Complexe operator-(const Complexe& other) const;
    Complexe operator*(const Complexe& other) const;
    Complexe operator/(const Complexe& other) const;
    bool operator==(const Complexe& other) const;
    void display() const;

};

void Complexe::display() const{
    cout<< Re <<"+"<<Im<<"i"<<endl;
}
Complexe Complexe::operator+(const Complexe& other) const{
    return Complexe(Re+other.Re, Im+other.Im);
}
Complexe Complexe::operator-(const Complexe& other) const{
    return Complexe(Re-other.Re, Im-other.Im);
}
Complexe Complexe::operator*(const Complexe& other) const{
    double NewRe= Re*other.Re - Im*other.Im;
    double NewIm= Re*other.Im + Im*other.Re;
    return Complexe(NewRe,NewIm);
}
Complexe Complexe::operator/(const Complexe& other) const{
    double Denom= other.Re*other.Re + other.Im*other.Im;
    if(Denom==0){
        throw runtime_error("Erreur car division par 0!");
    }
    double NewRe= (Re*other.Re + Im*other.Im)/Denom;
    double NewIm= (Im*other.Re - Re*other.Im)/Denom;
    return Complexe(NewRe,NewIm);
}
bool Complexe::operator==(const Complexe& other) const{
    return (Re==other.Re && Im==other.Im);
}


int main(){

    double Re1,Im1,Re2,Im2;
    int choix;

    cout<<"Entrez la valeur de la partie reelle du premier nombre: "<<endl;
    cin>>Re1;
    cout<<"Entrez la valeur de la partie imaginaire du premier nombre: "<<endl;
    cin>>Im1;

    cout<<"Entrez la valeur de la partie relle du deuxieme nombre: "<<endl;
    cin>>Re2;
    cout<<"Entrez la valeur de la partie imaginaire du deuxieme nombre: "<<endl;
    cin>>Im2;

    Complexe Num1(Re1,Im1);
    Complexe Num2(Re2,Im2);
    Complexe resultat;

    cout<<"Veuillez choisir une operation"<<endl;
    cout<<"1-Addition\n. 2-Soustraction\n. 3-Multiplication\n. 4-Division\n. 5-Egalite\n";
    cin>>choix;

    switch(choix){
    case 1:
        resultat= Num1 + Num2;
        cout<<"le resultat de l'addition est: "<<endl;
        resultat.display();
        break;

    case 2:
        resultat=Num1 - Num2;
        cout<<"le resultat de la soustraction est: "<<endl;
        resultat.display();
        break;

     case 3:
        resultat=Num1 * Num2;
        cout<<"le resultat de la multiplication est: "<<endl;
        resultat.display();
        break;

     case 4:
         try{
        resultat=Num1 / Num2;
        cout<<"le resultat de la division est: "<<endl;
        resultat.display();
         } catch (const runtime_error& e){
             cout<< e.what()<<endl;
         }
        break;

     case 5:
        if(Num1==Num2)
            cout<<"Ces nombres complexes sont egaux!"<<endl;
        else
            cout<<"Ces nombres complexes sont differents!"<<endl;
        break;

     default:
        cout<<"Choix invalide!"<<endl;
    }
    return 0;
}
