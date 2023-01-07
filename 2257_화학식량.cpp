#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<string> stackk;

void solution() {

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stackk.push("(");
		}
		else if (s[i] == 'C') {
			stackk.push("12");
		}
		else if (s[i] == 'H') {
			stackk.push("1");
		}
		else if (s[i] == 'O') {
			stackk.push("16");
		}
		else if (s[i] == ')') {
			int tmp = 0;
			while (!stackk.empty() && stackk.top() != "(") {
				tmp += stoi(stackk.top());
				stackk.pop();
			}
			stackk.pop();
			stackk.push(to_string(tmp));
		}
		else if ('2' <= s[i] && s[i] <= '9') {
			int num = s[i] - '0';
			int top = stoi(stackk.top());
			stackk.pop();
			string s = to_string(num * top);
			stackk.push(s);
		}
	}

	int ans = 0;
	while (!stackk.empty()) {
		ans += stoi(stackk.top());
		stackk.pop(); 
	}
	cout << ans;

}

void input() {
	cin >> s;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}