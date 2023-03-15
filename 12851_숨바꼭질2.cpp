#include <iostream>
#include <queue>
//0부터 100000 < 200000 [ 200001 ]
using namespace std;

int n; //현재 점
int k; //동생 점

int dp[200001];
int ans = 9999999;
int ans_time = 0;

void reset() {

	for (int i = 0; i <= 200000; i++) {
		dp[i] = 9999999;
	}
}

//5에서 17
//5 -> 4 -> 8 -> 16 -> 17
void solution() {

	reset();

	queue<pair<int, int>> q;
	//위치와 시간 

	q.push({ n, 0 });

	while (!q.empty()) {

		int now_position = q.front().first;
		int now_time = q.front().second;

		dp[now_position] = now_time;

		q.pop();

		if (now_position == k) {
			if (now_time < ans) {
				ans = now_time;
				ans_time = 1;
			}
			else if (now_time == ans) {
				ans_time++;
			}
			else {
				break;
			}
		}

		if (now_position + 1 <= 200000 && (now_time + 1 <= dp[now_position + 1])) {
			q.push({ now_position + 1, now_time + 1 });
		}

		if (now_position - 1 >= 0 && (now_time + 1 <= dp[now_position - 1])) {
			q.push({ now_position - 1, now_time + 1 });
		}

		if (now_position * 2 <= 200000 && (now_time + 1 <= dp[now_position * 2])) {
			q.push({ now_position * 2, now_time + 1 });
		}
	}

	cout << ans << "\n" << ans_time;

}
void input() {

	cin >> n >> k;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}