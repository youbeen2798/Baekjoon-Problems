#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n; //���� ��
int k; //������Ʃ�갡 ���� �����ϴ� ���� ����
int m; //������Ʃ�� ����
bool visited_hypertube[1001];
bool visited_station[100001];
vector<int> hypertubes[1001];
vector<int> stations[100001];
//1�� ���� ����� ������Ʃ�� ���� : hypertubes

int ans = 999999;

void bfs(int station, int times) {

	queue<pair<int, int>> q;

	q.push({ 1,0 });

	while (!q.empty()) {
		int now_station = q.front().first;
		int now_time = q.front().second;

		q.pop();

		if (now_station == n) {
			ans = min(ans, now_time + 1);
			continue;
		}

		for (int i = 0; i < stations[now_station].size(); i++) {
			int hypertube = stations[now_station][i]; //����� ������Ʃ��
			//1, 2

			if (!visited_hypertube[hypertube]) {
				visited_hypertube[hypertube] = true;

				for (int j = 0; j < hypertubes[hypertube].size(); j++) {

					int next_station = hypertubes[hypertube][j]; //���� ��

					if (next_station == station) {
						continue;
					}
					if (!visited_station[next_station]) {
						q.push({ next_station, now_time + 1 });
						visited_station[next_station] = true;
					}
				}
			}
		}
	}

}
void solution() {

	bfs(1, 0);

	if (ans == 999999) {
		cout << -1;
		exit(0);
	}
	cout << ans;

}
void input() {

	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int num;
			cin >> num;
			stations[num].push_back(i); //num�� ���� i�� ������Ʃ�갡 ����
			hypertubes[i].push_back(num); //i�� ������Ʃ�꿡 ���� ����ִ��� 
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