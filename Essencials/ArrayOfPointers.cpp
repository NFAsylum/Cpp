#include <iostream>
#include <vector>

using namespace std;

int main(){
    cout << "How many rows do you want to generate?" << endl;
    int rows;
    cin >> rows;
    cout << endl;

    int **arr = new int*[rows];

    //Initialize and allocate the array
    for (int r = 0; r < rows; r++){
        arr[r] = new int[r + 1];

        for (int c = 0; c <= r; c++)
            arr[r][c] = (r + 1) * 10 + c + 1;
    }

    //Print the array
    for (int r = 0; r < rows; r++){
        for (int c = 0; c <= r; c++)
            cout << arr[r][c] << " ";
        cout << endl;
    }


    //Free the array
    for (int r = 0; r < rows; r++)
        delete[] arr[r];
    delete[] arr;
}
