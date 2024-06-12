#include <iostream>

using namespace std;

class SuperClass{

private:
    int storage;

public:
    void setVal(int val){
        storage = val;
    }

    int getVal(){
        return storage;
    }
};

class SubClass : public SuperClass{};

int main(){
    SubClass a, b;

    a.setVal(100);
    b.setVal(a.getVal() + 1);
    cout << b.getVal() << endl;
}
