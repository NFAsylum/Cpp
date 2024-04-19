#include <iostream>

using namespace std;


float squareOfNum(float num){
    float result = num * num;

    return result;
}


int main(){
    float arg = 3.0;

    cout << "The second power of " << arg << " is " << squareOfNum(arg);

    return 0;
}
