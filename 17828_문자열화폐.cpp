#include <iostream>

using namespace std;

int n;
long x;
int arr[5000001];
char alphabets[27];
long namuzi = 0;

void print() {
	for (int i = 0; i < n; i++) {
		cout << alphabets[arr[i]];
	}
}
void solution() {

	char c = 'A';
	for (int i = 1; i <= 26; i++) {
		alphabets[i] = c;
		c++;
	}

	if (n > x) {
		cout << "!";
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}

	namuzi = x - n;
	int idx = n - 1;

	while (true) {
		
		if (idx < 0) {
			cout << "!";
			exit(0);
		}
		if (namuzi > 25) {
			arr[idx] += 25;
			namuzi -= 25;
		}
		else {
			arr[idx] += namuzi;
			namuzi = 0;
			break;
		}
		idx--;
	}

	print(); //AAAAZZ


	
}
void input() {
	cin >> n >> x;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}