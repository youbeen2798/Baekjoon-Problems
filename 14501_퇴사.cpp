#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ti, pi;

vector <pair<int, int>> v;

int maxx = 0;

void solution(int ti, int pi) { //1 0

//	cout << "ti: " << ti << " " << "pi: " << pi << "\n";

	if (ti > n) {
		maxx = max(pi, maxx);
		return;
	}
	solution(ti + 1, pi);

	if (ti > n || ti + v[ti].first > n + 1 ) {
		maxx = max(pi, maxx);
		return;
	}


	solution(ti + v[ti].first, pi + v[ti].second); //해당 날짜에 상담을 했을 때
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	v.push_back({ 0,0 });

	for (int i = 0; i < n; i++) {
		cin >> ti >> pi;
		v.push_back({ ti,pi });
	}

	solution(1, 0);

	cout <<  maxx;
}