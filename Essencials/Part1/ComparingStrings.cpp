#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Enter your password: " << endl;

    string input, input2;
    getline(cin, input);

    cout << "Repeat your password: " << endl;
    getline(cin, input2);

    if (input == input2){
        cout << "Your password is correct" << endl;
    }
    else{
        cout << "Your password is wrong" << endl;
    }
}
