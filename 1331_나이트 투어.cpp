#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector <pair<char, int>> v(36);

	for (int i = 0; i < 36; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < 35; i++) {
		if (abs(v[i].first - v[i + 1].first) == 2 && abs(v[i].second - v[i + 1].second) == 1) { //칸과 칸 사이의 차이가 2 1
			continue;
		}
		else if (abs(v[i].first - v[i + 1].first) == 1 && abs(v[i].second - v[i + 1].second) == 2) { //칸과 칸 사이의 차이가 1 2
			continue;
		}
		else {
			cout << "Invalid"; //칸과 칸 사이의 차이가 2 1 혹은 1 2가 아니라면
			return 0;
		}
	}

	if (abs(v[35].first - v[0].first) == 2 && abs(v[35].second - v[0].second) == 1) { 	//마지막 칸에서 첫번째 칸의 차이가 2 1
	}
	else if (abs(v[35].first - v[0].first) == 1 && abs(v[35].second - v[0].second) == 2) { //마지막 칸에서 첫번째 칸의 차이가 1 2
	}
	else {
		cout << "Invalid"; 	//마지막 칸에서 첫번째 칸의 차이가 2 1 혹은 1 2가 아니라면
		return 0;
	}


	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end()); // 겹치는 중복 원소 제거

	//중복 원소 확인
	if (v.size() != 36) { // 겹치는 원소가 있다면, 모든 칸을 방문하지 않은것이므로
		cout << "Invalid"; //Invalid 출력
		return 0;
	}
	else {
		cout << "Valid"; //겹치는 원소도 없고, 칸과 칸 사이의 차이가 모두 2 1 혹은 1 2이므로
	}
}