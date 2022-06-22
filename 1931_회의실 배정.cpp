#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n;

pair <int, int> p[100005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> p[i].second >> p[i].first;
	}

	sort(p, p + n);

	int t = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (t > p[i].second) {
			continue;
		}
		t = p[i].first;
		answer++;
	}

	cout << answer;
}