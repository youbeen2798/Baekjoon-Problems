#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t, n;
vector <pair<int, int>> location;
vector <int> domain[102];
bool visited[101];

void dfs(int start) {

	visited[start] = true;

	for (int i = 0; i < domain[start].size(); i++) {
		int next = domain[start][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int dist(int a, int b) { //두 위치의 거리
	return abs(location[a].first - location[b].first)
		+ abs(location[a].second - location[b].second);
}

void output() {

	if (visited[n + 1]) {
		cout << "happy" << "\n";
	}
	else {
		cout << "sad" << "\n";
	}
}
void input() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(visited, false, sizeof(visited));
		location.clear();

		for (int j = 0; j < 102; j++) {
			domain[j].clear(); 
		}
		cin >> n;

		for (int j = 0; j < n + 2; j++) {
			int x;
			int y;
			cin >> x >> y;
			location.push_back({ x,y });
		}

		for (int j = 0; j < n + 2; j++) {
			for (int k = j + 1; k < n + 2; k++) {
				if (dist(j, k) <= 50 * 20) { //둘 사이의 거리를 맥주 20캔으로 갈 수 있다면
					domain[j].push_back(k);
					domain[k].push_back(j);
				}
			}
		}

		dfs(0);
		output();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}