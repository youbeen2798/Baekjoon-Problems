#include <iostream>
#include <vector>
using namespace std;

int n;
int m;
int map[51][51];
//0: ºóÄ­, 1: Áý, 2: Ä¡Å²Áý

vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;
int ans = 9999999;

void check_diff(vector<pair<int, int>> selected_chickens) {

	int tmp_ans = 0; 
	for (int i = 0; i < homes.size(); i++) {
		int home_x = homes[i].first;
		int home_y = homes[i].second;

		int min_dist_diff = 99999;
		for (int j = 0; j < selected_chickens.size(); j++) {
			int chicken_x = selected_chickens[j].first;
			int chicken_y = selected_chickens[j].second;

			int diff = abs(home_x - chicken_x) + abs(home_y - chicken_y);
			min_dist_diff = min(min_dist_diff, diff);
		}
		tmp_ans += min_dist_diff;
	}

	ans = min(ans, tmp_ans);
}
void combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {
	
	if (r == 0) {
		check_diff(comb);
		/*
		cout << "###########" << "\n";
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i].first << " " << comb[i].second << "\n";
		}
		*/
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		comb[idx] = arr[depth];

		combination(arr, comb, r - 1, idx + 1, depth + 1);

		combination(arr, comb, r, idx, depth + 1);
	}
}
void solution() {

	vector<pair<int, int>> comb(m);

	combination(chickens, comb, m, 0, 0);
}
void input() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chickens.push_back({ i,j });
			}
			else if (map[i][j] == 1) {
				homes.push_back({ i,j });
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