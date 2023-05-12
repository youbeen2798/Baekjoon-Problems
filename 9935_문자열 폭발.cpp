#include <iostream>
#include <stack>
using namespace std;

string st;
string bomb_st;

void solution() {

	string new_bomb_st;

	for (int i = bomb_st.size() - 1; i >= 0; i--) {
		new_bomb_st += bomb_st[i];
	}
	bomb_st = new_bomb_st; 

	stack<char> s;

	for (int i = 0; i < st.size(); i++) {
		s.push(st[i]);

		if (st[i] == bomb_st[0] && s.size() >= bomb_st.size()) {
			string new_st = "";
			for (int j = 0; j < bomb_st.size(); j++) {
				new_st += s.top();
				s.pop();
			}
			if (new_st != bomb_st) { //폭발 안 한다면 
				for (int j = new_st.size() - 1; j >= 0; j--) {
					s.push(new_st[j]);
				}
			}
			else {
			}
		}
	}
	
	string reverse_ans = "";
	while (!s.empty()) {
		reverse_ans += s.top();
		s.pop();
	}

	string ans = "";
	for (int i = reverse_ans.size() - 1; i >= 0; i--) {
		ans += reverse_ans[i];
	}

	if (ans.size() == 0) {
		cout << "FRULA" << "\n";
	}
	else {
		cout << ans << "\n";
	}
}

void input() {
	cin >> st >> bomb_st;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}