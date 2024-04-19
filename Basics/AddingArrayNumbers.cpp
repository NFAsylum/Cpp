#include <iostream>
#include <vector>

using namespace std;

int main(){
     vector<int> numbers(5);

     cout << "Type 5 numbers:" << endl;
     for (int i = 0; i < numbers.size(); i++){
        cin >> numbers[i];
     }

     int sum = 0;
     for (int x = 0; x < numbers.size(); x++){
        sum += numbers[x];
     }

     cout << "The sum of the five numbers is " << sum << endl;
}
