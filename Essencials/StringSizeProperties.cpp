#include <iostream>
#include <string>

using namespace std;

void stringInfo(string& value){
    cout << "Length: " << value.length() << endl;
    cout << "Capacity: " << value.capacity() << endl;
    cout << "Max size: " << value.max_size() << endl;
    cout << "-------------------" << endl;
}

int main(){
    string str = "content";

    stringInfo(str);

    for (int i = 0; i < 10; i++){
        str += str;
    }

    stringInfo(str);
}
