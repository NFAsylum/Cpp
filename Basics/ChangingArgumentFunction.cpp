#include <iostream>

using namespace std;


int does_not_change_my_argument(int num){
    num++;
    return num;
}

int change_my_argument(int& num){
    num++;

    return num;
}


int main(){
    int variable1 = 1, variable2 = 1;

    does_not_change_my_argument(variable1);
    change_my_argument(variable2);

    cout << "The first function can not change the variable: " << variable1 << endl;
    cout << "The second function can change the variable: " << variable2 << endl;

    return 0;
}
