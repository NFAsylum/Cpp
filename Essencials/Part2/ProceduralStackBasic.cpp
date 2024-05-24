#include <iostream>

using namespace std;

int stack[100];
int SP = 0;

void push(int value){
    stack[SP++] = value;
}

int pop(){
    return stack[--SP];
}

int main(){
    push(10);
    push(3);
    push(5);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
