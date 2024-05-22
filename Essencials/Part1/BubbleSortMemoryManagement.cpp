#include <iostream>

using namespace std;

int main(){
    int howManyNumbers = 0;
    bool swapped;

    cout << "How many numbers do you want to sort?" << endl;
    cin >> howManyNumbers;

    int *arr = new int[howManyNumbers];

    for (int i = 0; i < howManyNumbers; i++){
        cout << "Type the #" << i + 1<< " number: ";
        cin >> arr[i];
    }

    do{
        swapped = false;

        for (int i = 0; i < howManyNumbers - 1; i++){
            if (arr[i] > arr[i + 1]){
                swapped = true;

                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
        }
    } while (swapped);

    for (int i = 0; i < howManyNumbers; i++){
        cout << arr[i] << endl;
    }

    delete[] arr;
}
