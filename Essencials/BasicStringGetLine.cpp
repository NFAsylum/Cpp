#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Type a phase: " << endl;

    string input;
    getline(cin, input);

    cout << "You typed: " << endl;
    cout << input << endl;
}
