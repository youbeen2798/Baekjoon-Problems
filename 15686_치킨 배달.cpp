#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int map[51][51];
vector <pair<int, int>> homes;
vector <pair<int, int>> chicken;
vector <vector<int>> home_to_chicken(101); //각 집에서 치킨집까지의 거리

int mini = 100000000;

void solution(vector <int> a) { // 0 2
	int dist = 0;

	for (int i = 0; i < homes.size(); i++) { // 1 2 6
		vector <int> b;

		for (int j = 0; j < a.size(); j++) {
			b.push_back(home_to_chicken[i][a[j]]); // 1 2
		}

		sort(b.begin(), b.end());

		dist += b[0]; // 1 2 1 1
	}

	if (dist < mini) {
		mini = dist;
	}
}



void Combination(vector <int> arr, vector <int> comb, int r, int index, int depth) {
	if (r == 0) {

		solution(comb);
	}
	else if (depth == arr.size()) {
		return;
	}
	else {

		//arr[depth]를 뽑은 경우
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1);

		//arr[depth]를 뽑지 않은 경우
		Combination(arr, comb, r, index, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				homes.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}



	for (int i = 0; i < homes.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			home_to_chicken[i].push_back(abs(homes[i].first - chicken[j].first) +  abs(homes[i].second - chicken[j].second));
		}
	}

	vector <int> arr;

	for (int i = 0; i < chicken.size(); i++) {
		arr.push_back(i);
	}

	vector <int> comb(m);

	Combination(arr, comb, m, 0, 0);

	cout <<  mini << "\n";
}