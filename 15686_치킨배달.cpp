#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n; //도시 크기
int m; //치킨
int arr[51][51];
int ans = 99999;

vector<pair<int, int>> chickens;
set<pair<int, int>> homes;

void check_dist(vector<pair<int, int>> chickens) {

	int tmp_total_min_dist = 0;

	for (auto home : homes) {
		int min_dist = 99999;

		for (int i = 0; i < chickens.size(); i++) {
			int dist = abs(home.first - chickens[i].first) + abs(home.second - chickens[i].second);
			min_dist = min(min_dist, dist);
		}
		tmp_total_min_dist += min_dist;
	}

	ans = min(ans, tmp_total_min_dist);
}
void combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int depth, int idx) {

	if (r == 0) {
		check_dist(comb);
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		comb[idx] = arr[depth];
		combination(arr, comb, r - 1, depth + 1, idx + 1);

		combination(arr, comb, r, depth + 1, idx);
	}
}
void solution() {

	vector<pair<int, int>> comb(m);

	combination(chickens, comb, m, 0, 0);
}
void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				chickens.push_back({ i,j });
			}
			else if (arr[i][j] == 1) {
				homes.insert({ i,j });
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solution();
	cout << ans;
}