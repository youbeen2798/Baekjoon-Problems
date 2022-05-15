#include <iostream>
#include <vector>
using namespace std;

int a, b;
int n, m;
bool visited[1001] = { 0, };
int cnt = 0;
vector <int> v[1001];

void dfs(int k) {
	visited[k] = 1;

	for (int i = 0; i < v[k].size(); i++) {
		int hello = v[k][i]; // 1
		if (visited[hello] == 0) {
			dfs(hello);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);

	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0  && v[i].size() > 0) {
			cnt++;
			dfs(i);
		}
	}

	//홀로 남은 정점 더하기
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			cnt++;
		}
	}


	cout << cnt << "\n";
	
}