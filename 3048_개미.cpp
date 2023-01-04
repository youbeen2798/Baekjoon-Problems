#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int n1, n2; //개미의 수
int t;
set<char> set1;
set<char> set2;
string final_st;
string answer;

void input() {
	string s1, s2;

	cin >> n1 >> n2; //
	cin >> s1 >> s2;

	reverse(s1.begin(), s1.end());

	final_st += s1 + s2;

	for (int i = 0; i < s1.size(); i++) {
		set1.insert(s1[i]);
	}
	
	for (int i = 0; i < s2.size(); i++) {
		set2.insert(s2[i]);
	}

	cin >> t; //시간
}
//a,b 바꾸기
//tmp = a;
//a = b;
//b = tmp;
void solution() {

	//s1 = ABC, s2 = DEF
	//CBADEF

//	cout << "final_st: " << final_st << "\n";
	while (t--) {
		for (int i = 0; i < final_st.size() - 1; i++) {
			if (set1.find(final_st[i]) != set1.end() && set2.find(final_st[i+1]) != set2.end()) {
//				cout << "i: " << final_st[i] << " " << "i+1: " << final_st[i + 1] << "\n";
				char tmp = final_st[i];
				final_st[i] = final_st[i + 1];
				final_st[i + 1] = tmp;
				answer += final_st[i] + final_st[i + 1];
				i++;
			}
		}
	}

	cout << final_st;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}