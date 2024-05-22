#include <iostream>

using namespace std;

namespace Hogwarts{
    int trollAmount = 1;
}

namespace Mordor{
    int trollAmount = 5;
}

int main(){
    cout << "Hogwarts have " << Hogwarts::trollAmount << " troll(s)" << endl;
    cout << "Mordor have " << Mordor::trollAmount << " troll(s)";
}
