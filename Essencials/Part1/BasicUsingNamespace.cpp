#include <iostream>

using namespace std;

namespace Hogwarts{
    int trollAmount = 1;
}

namespace Mordor{
    int trollAmount = 5;
}

int main(){
    {
        using namespace Hogwarts;
        cout << trollAmount << " troll(s) in this region" << endl;
    }

    {
        using namespace Mordor;
        cout << trollAmount << " troll(s) in this another region" << endl;
    }
}
