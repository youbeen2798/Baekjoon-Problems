#include <iostream>

using namespace std;

int n;
int num;
int st, en;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int* sent = new int[n+1];

	for (int i = 1; i <= n; i++) {
		cin >> sent[i];
	}
	
	bool** arr = new bool* [n + 2];

	for (int i = 0; i < n+2; i++) {
		arr[i] = new bool[n + 2];
	}

	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			arr[i][j] = true;
		}
	}


	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (i <= j) {
				if (sent[i] != sent[j] || !arr[i+1][j-1]) {
					arr[i][j] = false;
				}		
			}	
		}
	}
	
	cin >> num;

	int a, b;

	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		if (arr[a][b]) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

}