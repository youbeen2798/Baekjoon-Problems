#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> a;
	cin >> b;

	cout << a * ( b % 10) << endl; //1
	cout << a * ((b % 100) / 10) << endl;
	cout << a * (b / 100) << endl;
	cout << a * b;

	return 0;
	
}