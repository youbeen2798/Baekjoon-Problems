#include <iostream>
#include <algorithm>

#define MAX 987654321

using namespace std;

int n;
int cnt = 0;
string st, dt, temp;
int ans = MAX;

void lightOn(int idx) {	
	if (idx > 0) {
		temp[idx - 1] = (temp[idx - 1] == '0') ? '1' : '0';
	}
	temp[idx] = (temp[idx] == '0') ? '1' : '0';

	if (idx < n - 1) {
		temp[idx+1] = (temp[idx+1] == '0') ? '1' : '0';
	}
}
void solve(int first) {
	temp = st;
	cnt = 0;

	if (first == 0) {
		temp[0] = (temp[0] == '0') ? '1' : '0';
		temp[1] = (temp[1] == '0') ? '1' : '0';
		cnt++;
	}

	for (int i = 1; i < n; i++) {
		if (temp[i - 1] != dt[i - 1]) {
			lightOn(i);
			cnt++;
		}
	}

	if (temp == dt) {
		ans = min(ans,cnt);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> st >> dt;

	solve(0);
	solve(1);
	
	if (ans != MAX) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}