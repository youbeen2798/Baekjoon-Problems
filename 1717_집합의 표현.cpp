#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

int get_parent(int num) {
	if (num == parent[num]) {
		return num;
	}
	return parent[num] = get_parent(parent[num]);
}
void union_find(int b, int c) {

	b = get_parent(b); //b의 부모
	c = get_parent(c); //c의 부모

	if (b < c) { //c의 부모가 더 크면
		parent[c] = b;
	}
	else if (c < b) { //b의 부모가 더 크면
		parent[b] = c;
	}
}

string find_num(int b, int c) {

	if (get_parent(b) == get_parent(c)) {
		return "YES";
	}
	return "NO";
}
void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			union_find(b, c);
		}
		else if (a == 1) {
			cout << find_num(b, c) << "\n";
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}