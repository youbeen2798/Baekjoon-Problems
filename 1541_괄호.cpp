#include <iostream>
#include <vector>
#include <string>

using namespace std;

string st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> st;

	vector <int> h1;
	vector <char> h2;
	vector <int> tmp;

	for (int i = 0; i < st.size(); i++) {
		if (st[i] == '+' || st[i] == '-') {
			h2.push_back(st[i]);

			int result = 0;
			int hi = 1;
			for (int j = tmp.size() - 1; j >= 0; j--) {
				result += hi * tmp[j];
				hi *= 10;
			}
			tmp.clear();
			h1.push_back(result);
		}
		else {
			int k = st[i] - '0';
			tmp.push_back(k);
		}
	}

	int result = 0;
	int hi = 1;

	for (int i = tmp.size() - 1; i >= 0; i--) {
		result += tmp[i] * hi;
		hi *= 10;
	}
	h1.push_back(result);


	bool hello = false;
	for (int i = 0; i < h2.size(); i++) {
		if (h2[i] == '-') {
			hello = true;
		}
		if (hello) {
			h2[i] = '-';
		}
	}

	int num = 0;
	for (int i = 0; i < h2.size(); i++) {
		if (h2[i] == '-') {
			num = i + 1;
			break;
		}
	}

	result = 0;
	if (num == 0) {
		for (int i = 0; i < h1.size(); i++) {
			result += h1[i];
		}
	}
	else {
		for (int i = 0; i < num; i++) {
			result += h1[i];
		}
		for (int i = num; i < h1.size(); i++) {
			result -= h1[i];
		}
	}

	cout << result;

}