//N개의 자연수와 자연수 M이 주어졌을 때,
//아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램
//N개의 자연수는 모두 다른 수
//고른 수열은 오름차순이어야 함
//수열은 사전 순으로 증가하는 순서로 출력해야 함
// 중복되는 수열을 여러 번 출력하면 안됨
// 각 수열은 공백을 구분해서 출력

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];

void func(int k, vector <int> vs) {
	if (k == m) {						
		for (int i = 0; i < m; i++) {     
			cout << arr[i] << ' ';  
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < n ; i++) {
				arr[k] = vs[i]; 
				func(k+1, vs); 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	func(0, v);


}
