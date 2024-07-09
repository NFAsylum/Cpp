#include <iostream>

using namespace std;

float div(float a, float b)
{
	if(b == 0.0)
		throw string("can't divide by zero :(");
	return a / b;
}

int main()
{
	float a, b;
	
	while(cin >> a) {
		try {
			cin >> b;
			cout << div(a, b) << endl;
		} catch (string &problem) {
			cout << "Look what you did, you bad user!" << endl;
			cout << problem << endl;
		}
	}
	cout << "End" << endl;
}
