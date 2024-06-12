#include <iostream>

using namespace std;

class SuperClass{

protected:
    int storage;

public:
    void setVal(int val){
        storage = val;
    }

    int getVal(){
        return storage;
    }
};

class SubClass : public SuperClass{

    public:
        void printVal(){
            cout << "storage = " << storage << endl;
        }
};

int main(){
    SubClass a, b, c;

    a.setVal(100);
    b.setVal(a.getVal() + 1);
    c.setVal(b.getVal() * 2);
    c.printVal();
}
