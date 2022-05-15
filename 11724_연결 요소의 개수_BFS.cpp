#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int cnt = 0;
bool visited[1001];
vector <int> v[1001];
queue <int> q;

void bfs(int k) {
	visited[k] = 1;
	q.push(k); 

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < v[k].size(); i++) {
			int a = v[k][i];
			if (visited[a] == 0) {
				visited[a] = 1; 
				q.push(a); 
			}		
		}
	}

	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0 && v[i].size() > 0) {
			bfs(i);
			cnt++;
		}
	}
	//정점 노드 더하기
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			cnt++;
		}
	}

	cout << cnt << "\n";


}
