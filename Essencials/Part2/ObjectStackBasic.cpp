#include <iostream>

using namespace std;

class Stack{
private:
    int stackstore[100];
    int SP;

public:
    Stack(){
        SP = 0;
    }
    void push(int value);
    int pop(){
        return stackstore[--SP];
    }
};

void Stack::push(int value){
    stackstore[SP++] = value;
}

int main(){

    Stack littleStack, anotherStack, finalStack;

    littleStack.push(1);
    anotherStack.push(littleStack.pop() + 2);
    finalStack.push(anotherStack.pop() + 3);

    cout << finalStack.pop();
}
