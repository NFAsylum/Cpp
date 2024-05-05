#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1 = "ABCDEF", str2;
    str2 = str1.substr(0, 1) + str1.substr(4) + str1.substr();

    cout << str2;
}
