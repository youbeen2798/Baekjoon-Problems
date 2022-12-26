#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int k; //테스트 케이스 개수
vector <int> node[20001];
bool visited[20001];
bool check[20001];
queue <int> q;
bool answer;

void bfs(int start) { //시작 정점

	check[start] = true;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		for (int i = 0; i < node[a].size(); i++) {
			int now_node = node[a][i]; //현재 노드
			if (!visited[now_node]) { //아직 노드가 방문되지 않았다면
				q.push({ now_node });
				visited[now_node] = true; //방문 처리
				check[now_node] = !check[a];
			}
			else {
				if (check[a] == check[now_node]) {
					answer = false;
				}
			}
		}
	}

}
void input() {
	cin >> k;

	for (int test_case = 0; test_case < k; test_case++) {
		memset(node, {}, sizeof(node));

		int v, e;
		cin >> v >> e;  //정점의 개수, 간선의 개수

		for (int i = 0; i < e; i++) {
			int start, end;
			cin >> start >> end; //두 정점의 번호

			node[start].push_back(end);
			node[end].push_back(start);
			answer = true;
		}

		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));

		for (int i = 1; i <= v; i++) {
			if (!visited[i]) {
				bfs(i);
			}
		}

		if (answer) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

}