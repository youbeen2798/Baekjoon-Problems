#include <iostream>
#include <queue>

using namespace std;

int A, B;
int cnt;
int cnt2 = 0;
queue <int> q;
int k = 1;
int bfs(int x, int y) { 
	cnt = 1;
	q.push(x); 

	while (!q.empty()) {
		k++;
		while (cnt--) {
			long long a = q.front(); 
			q.pop();

			if (2 * a < B) {
				q.push(2 * a);
				cnt2++;
			}
			if (2 * a == B) {
				cout << k << "\n";
				return 0;
			}

			if (10 * a + 1 < B) {
				q.push(10 * a + 1);
				cnt2++;
			}

			if (10*a + 1 == B) {
				cout << k << "\n";
				return 0;
			}

		}
		cnt = cnt2;
		cnt2 = 0; 
	}
	cout << "-1" << "\n";
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;
	bfs(A, B);
	
}