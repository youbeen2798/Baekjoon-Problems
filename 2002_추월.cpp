#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<string> entrance;
vector <string> exitt;

int n;
int ans = 0;
void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		entrance.push_back(st);
	}

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		exitt.push_back(st);
	}
}
//a b c d e //본래 위치보다 앞으로 가면 추월
//e a b c d

//a b c d e
//b a d c e

//a b c d e
//b c d a e

//a b c d
//d a c b //앞에 있던 애가 앞에 없어지면 추월한 것임
void solution() {
	for (int i = 0; i < n; i++) {
		string st = entrance[i]; //a
		set<string> s1;
		set<string> s2;
		for (int k = 0; k < i; k++) {
			s1.insert(entrance[k]);
		}
		
//		cout << "st: " << st << "\n";
//		cout << "s1.size: " << s1.size() << "\n";

		for (int j = 0; j < n; j++) {
			if (exitt[j] == st) {
				for (int k = 0; k < j; k++) {
					s2.insert(exitt[k]);
				}

//				cout << "s2.size: " << s2.size() << "\n";
				for (auto tmp : s1) {
					if (s2.find(tmp) == s2.end()) {
						ans++;
						break;
					}
				}
			}
		}
	}
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}