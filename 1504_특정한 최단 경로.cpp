#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int n, e;
int n1, n2;
int Dist[801];
vector <pair<int, int>> vt[801];
queue <pair<int, int>> pq;

int solution(int start, int end) {

	for (int i = 1; i <= n; i++) {
		Dist[i] = INF; //최장 거리
	}

	pq.push({ 0, start }); //첫번째 인자 : 거리, 두번째 인자: 시작점

	while (!pq.empty()) {
		int dist = - pq.front().first; //첫번째 거리
		int node = pq.front().second; //시작점

		pq.pop();

		for (int i = 0; i < vt[node].size(); i++) {//다음 노드
			int nNode = vt[node][i].first; //다음 노드
			int nDist = vt[node][i].second; //다음 거리

			if (Dist[nNode] > dist + nDist) {
				Dist[nNode] = dist + nDist;
				pq.push({ -Dist[nNode], nNode });
			}
		}
	}

	return Dist[end];

}
void input() {
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c; //양방향 길이 존재
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}
	cin >> n1 >> n2;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	int dist1_a = solution(1, n1);
	int dist1_b = solution(n1, n2);
	int dist1_c = solution(n2, n);

	int dist1 = dist1_a + dist1_b + dist1_c;
	
	if (dist1_a == INF || dist1_b == INF || dist1_c == INF) {
		dist1 = INF;
	}

	int dist2_a = solution(1, n2);
	int dist2_b = solution(n2, n1);
	int dist2_c = solution(n1, n);

	int dist2 = dist2_a + dist2_b + dist2_c;

	if (dist2_a == INF || dist2_b == INF || dist2_c == INF) {
		dist2 = INF;
	}

	if (min(dist1, dist2) == INF) {
		cout << -1;
	}
	else {
		cout << min(dist1, dist2); 
	}
}