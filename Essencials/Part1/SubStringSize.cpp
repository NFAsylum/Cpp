#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1 = "12345", str2;
    int pos = 1;

    cout << str1.substr(pos).substr(pos).substr(pos).size();
}
