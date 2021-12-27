#include <iostream>

using namespace std;

int main() {
	int a,b,c;
	cin >> a;
	for (int i = 1; i < a+1; i++) {
		cin >> b >> c;
		cout << "Case #" << i << ": " << b + c << "\n";
	}
	return 0;
}