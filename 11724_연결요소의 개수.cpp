#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector <int> v[100001];
bool visited[100001];
int answer[100001];
queue<int> q;

void input() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void bfs(int start) {

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int a = q.front();
		q.pop(); 

		for (int i = 0; i < v[a].size(); i++) {
			int num = v[a][i];
			if (!visited[num]) {
				answer[num] = a;
				visited[num] = true;
				q.push(num);
			}
		}
	}
}
void solution() {
	
	bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << answer[i] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solution();
}