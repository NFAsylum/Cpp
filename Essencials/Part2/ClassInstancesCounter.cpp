#include <iostream>

using namespace std;

class Class{
public:
    static int counter;

    Class(){
        ++counter;
    }

    ~Class(){
        --counter;

        if (counter == 0){
            cout << "Bye, bye!" << endl;
        }
    }

    void HowMany(){
        cout << "Number of instances: " << counter << endl;
    }
};

int Class::counter = 0;

int main(){

    Class a, b;
    cout << Class::counter << " instances so far." << endl;

    Class c, d, e;

    d.HowMany();
}
