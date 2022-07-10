#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int test_case;
int k;
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> test_case;

	for (int T = 0; T < test_case; T++) {
		cnt = 0;
		cin >> n >> m;

		vector <int> v;
		queue < pair<int, int>> q;
		
		for (int i = 0; i < n; i++) {
			cin >> k;
			v.push_back(k); // 1 2 3 4
			q.push(make_pair(k, i)); // (1,0), (2,1), (3,2), (4,3)
		}

		sort(v.rbegin(), v.rend());

		int hi = 0;
		int hi2 = 0;
		while (1) {
			while (1) {
				if (q.front().first != v[0]) {
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					q.push(make_pair(a, b));
				}
				else {
					hi2 = q.front().second;
					v.erase(v.begin() + 0);
					q.pop();
					break;
				}
			}
			cnt++;
			if (hi2 == m) {
				break;
			}
		}

		cout << cnt << "\n";
		
	
	}





}