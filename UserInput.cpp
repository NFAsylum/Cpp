#include <iostream>

using namespace std;

int main(){
    double age;
    string name;

    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your name: ";
    //cin >> name;
    cin.ignore();
    getline(cin, name);

    cout << "\nYou are " << age << " years old\n";
    cout << "Your name is " << name;

    return 0;
}
