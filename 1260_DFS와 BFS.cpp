#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001


int N, M, V; //��������, ��������, ��������
int map[MAX][MAX];
bool visited[MAX]; //���� �湮 ����
queue <int> q;

void reset() {
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

void DFS(int v) { //1 2
	visited[v] = true; 
	cout << v << ' '; //1 2 5 6 3

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == 0) { //���� ������ ����Ǿ� �ְ� �湮���� �ʾҴٸ�
			DFS(i); //5 6 3
		}
	}
}

void BFS(int v) { //1
	q.push(v); //1
	visited[v] = true; //1
	cout << v << ' '; //1
	
	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (map[v][i] == 1 && visited[i] == 0) {  //���� ������ ����Ǿ� �ְ� �湮���� �ʾҴٸ�
				q.push(i);
				visited[i] = true;
				cout << i << ' ';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	DFS(V);
	
	cout << '\n';

	reset();
	BFS(V);

	return 0;
}