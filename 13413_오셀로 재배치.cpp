#include <iostream>

using namespace std;

int t;
int ans = 0;

void solution(string s1, string s2) {

	int B_to_W = 0;
	int W_to_B = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == 'B' && s2[i] == 'W') {
			B_to_W++; //1
		}
		else if (s1[i] == 'W' && s2[i] == 'B') {
			W_to_B++; //3
		}
	}
	ans = min(B_to_W, W_to_B) + abs(W_to_B - B_to_W);
	cout << ans << "\n";	
}
void input() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		string s1, s2;
		cin >> num >> s1 >> s2;
		solution(s1, s2); 
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}