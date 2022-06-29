#include <iostream>
#include <queue>
using namespace std;

int n;

bool arr[100][100] = { 0, };
bool map[100][100];

bool visited[100];

queue <int> q;

void bfs(int x) {

	q.push(x);

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			if (map[a][i] == 1 && visited[i] == 0) {
				arr[x][i] = 1;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		bfs(i);
		for (int j = 0; j < n; j++) {
			visited[j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}