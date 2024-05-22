#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> sortVector = {0, 0, 0, 0, 0};
    bool swapped;

    for (int i = 0; i < 5; i++){
        cout << "Type the #" << i + 1<< " number:" << endl;
        cin >> sortVector[i];
    }

    do{
        swapped = false;

        for (int i = 0; i < 4; i++){
            if (sortVector[i] > sortVector[i + 1]){
                swapped = true;
                int aux = sortVector[i];
                sortVector[i] = sortVector[i + 1];
                sortVector[i + 1] = aux;
            }
        }
    } while (swapped);

    cout << "The sorted numbers are:" << endl;
    for (int i = 0; i < 5; i++){
        cout << sortVector[i] << " ";
    }

    return 0;
}
