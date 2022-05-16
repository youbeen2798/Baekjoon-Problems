#include <iostream>

using namespace std;

int A, B;
int mini = 1000000;
void dfs(long long a, int cnt) {

	if (a > B)
		return;
	else if (a == B) {
		mini = min(1000000, cnt);
	}
	else {
		dfs(2 * a, cnt + 1);
		dfs(10 * a + 1, cnt + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	dfs(A, 1);

	if (mini == 1000000)
		cout << "-1";
	else
		cout << mini;
}