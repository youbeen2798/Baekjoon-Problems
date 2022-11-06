#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999999
int v, e, k;
vector <pair<int, int>> vt[20001];
priority_queue<pair<int, int>> pq;
int Dist[20001];

void input() {
	cin >> v >> e >> k; //정점의 개수, 간선의 개수, 시작 정점의 번호


	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vt[a].push_back({ b,c }); //끝점과 가중치
	}

}

void solution() {

	for (int i = 0; i <= v; i++) {
		Dist[i] = INF;
	}

	pq.push({ 0,k }); //시작 정점의 거리와 번호
	Dist[k] = 0; //자기 자신으로의 거리는 0

	while (!pq.empty()) {
		int dist = -pq.top().first; //거리 //k
		int node = pq.top().second; //시작점 //0

		pq.pop();

		for (int i = 0; i < vt[node].size(); i++) {
			int nextNode = vt[node][i].first; //다음 점
			int nDist = vt[node][i].second; //다음 가중치

			if (Dist[nextNode] > dist + nDist) {
				Dist[nextNode] = dist + nDist; //거리 갱신
				pq.push({ -Dist[nextNode], nextNode });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (Dist[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << Dist[i] << "\n";
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}