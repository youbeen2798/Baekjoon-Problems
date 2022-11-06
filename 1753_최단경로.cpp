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
	cin >> v >> e >> k; //������ ����, ������ ����, ���� ������ ��ȣ


	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vt[a].push_back({ b,c }); //������ ����ġ
	}

}

void solution() {

	for (int i = 0; i <= v; i++) {
		Dist[i] = INF;
	}

	pq.push({ 0,k }); //���� ������ �Ÿ��� ��ȣ
	Dist[k] = 0; //�ڱ� �ڽ������� �Ÿ��� 0

	while (!pq.empty()) {
		int dist = -pq.top().first; //�Ÿ� //k
		int node = pq.top().second; //������ //0

		pq.pop();

		for (int i = 0; i < vt[node].size(); i++) {
			int nextNode = vt[node][i].first; //���� ��
			int nDist = vt[node][i].second; //���� ����ġ

			if (Dist[nextNode] > dist + nDist) {
				Dist[nextNode] = dist + nDist; //�Ÿ� ����
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