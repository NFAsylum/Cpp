#include <iostream>

using namespace std;


float square_of_num(float num){
    float result = num * num;

    return result;
}


int main(){
    float arg = 3.0;

    cout << "The second power of " << arg << " is " << square_of_num(arg);

    return 0;
}
