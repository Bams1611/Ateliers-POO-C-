#include <iostream>

using namespace std;

class Test {

private:
    static int count;

public:
    static void call() {
        ++count;
        cout<< "La fonction call a ete appelee " << count<<" " <<"fois"<< endl;
    }

};


int Test::count = 0;

int main() {
    Test::call();
    Test::call();
    Test::call();


    return 0;
}
