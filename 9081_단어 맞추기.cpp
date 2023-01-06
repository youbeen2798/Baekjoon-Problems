#include <iostream>
#include <algorithm>

using namespace std;

int t;


void solution(string s) {
	//s : BREE
	for (int i = s.size() - 2; i >= 0; i--) {
		char before_c = s[i]; //3
		char after_c = s[i + 1]; //5

		if (before_c < after_c) {
		//	cout << "before_c: " << before_c << "\n"; //B
		//	cout << "after_c: " << after_c << "\n"; //R
			string st = s.substr(i + 1, s.size() - 1); //REE
			sort(st.begin(), st.end()); //EER
		//	cout << "st: " << st << "\n"; //EER
			for (int j = 0; j < st.size(); j++) {
				if (before_c < st[j]) {
					char medium_c = st[j]; //E
					st.erase(st.begin() + j); //ER 
		//			cout << "st: " << st << "\n"; //ER
					st += before_c; //BER
		//			cout << "st: " << st << "\n"; //BER
					sort(st.begin(), st.end());
		//			cout << "i: " << i << "\n"; //BER
					cout << s.substr(0, i) + medium_c + st << "\n";
					return;
					//	exit(0);
				}
			}
		}
	}
	cout << s << "\n";
}
void input() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		string st;
		cin >> st;
		solution(st);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}