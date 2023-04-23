#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int c;
int n; //형택이가 홍보할 수 있는 도시 개수
int dp[1100]; //dp[1] = 3; //1명을 홍보하는데 3원이 듬
vector<pair<int, int>> info;
int ans = 999999999;

void solution() {

	queue < pair<int, int>> q;
	
	for (int i = 1; i <= 1100; i++) {
		dp[i] = 999999999;
	}

	for (int i = 0; i < info.size(); i++) {
		int people_num = info[i].first;
		int cost = info[i].second;
		q.push({ people_num, cost });
		dp[people_num] = cost;
	}

	int cnt = 0;
	while (!q.empty()) {
		int people_num = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (people_num >= c) {
			ans = min(ans, dp[people_num]);
			continue; 
		}
		for (int i = 0; i < info.size(); i++) {
			int plus_people_num = info[i].first;
			int plus_cost = info[i].second;

			int total_people_num = people_num + plus_people_num;
			int total_cost = cost + plus_cost;
			if (dp[total_people_num] > total_cost) {
				dp[total_people_num] = total_cost;
				q.push({ total_people_num, total_cost });
			}
		}
	}

	cout  << ans;
}

void input() {
	cin >> c >> n;

	for (int i = 0; i < n; i++) {
		int cost, customer_num;
		cin >> cost >> customer_num;
		info.push_back({ customer_num, cost });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}