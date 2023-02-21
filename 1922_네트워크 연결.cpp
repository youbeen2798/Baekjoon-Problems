#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
int ans_cost = 0;

int parent[1001];

vector < pair<int, pair<int, int>>> v;

int get_parent(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = get_parent(parent[x]);
}

void union_find(int x, int y, int cost) {
	
	x = get_parent(x);
	y = get_parent(y);

	if (x == y) {
		return;
	}
	else if (x > y) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
	}

	ans_cost += cost;
}
void solution() {

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int c1 = v[i].second.first;
		int c2 = v[i].second.second;
		int cost = v[i].first;

		union_find(c1, c2, cost);
	}

	cout << ans_cost;
}
void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {c}, {a,b} });
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}