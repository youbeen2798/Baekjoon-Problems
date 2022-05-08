//BFS 혹은 DFS로 푸는 문제 
//아래 코드는 BFS를 활용함


#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

bool map[MAX][MAX];
queue <int> q;
bool visited[MAX];

int N, M;
int sum = 0;

void BFS(int v) { 
	q.push(v);
	visited[v] = 1;

	while (!q.empty()) {
		v = q.front();
		q.pop(); 

		for(int i=1; i<= N; i++)
			if (map[v][i] == 1 && visited[i] == 0) {
				visited[i] = 1; 
				q.push(i); 
				sum++;
			}
	}
	cout << sum << "\n";

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	BFS(1);
}