#include <iostream>
#include <string>

using namespace std;

void stringInfo(string& value){
    cout << "Content:" << value << endl;
    cout << "Capacity: " << value.capacity() << endl;
    cout << "Is empty: " << (value.empty() ? "Yes" : "No") << endl;
    cout << "-------------------" << endl;
}

int main(){
    string str = "content";

    stringInfo(str);
    str.resize(30, '?');
    stringInfo(str);
    str.resize(4);
    stringInfo(str);
    str.clear();
    stringInfo(str);
}
