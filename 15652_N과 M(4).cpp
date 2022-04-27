//자연수 N과 M이 주어졌을 때, 길이가 M인 수열을 모두 출력하는 프로그램
// 단, 아래 조건을 만족해야함

//조건 1. 1부터 N까지 자연수 중에서 M개를 고른 수열
//조건 2. 같은 수를 여러 번 골라도 됨
//조건 3. 고른 수열은 비내림차순

#include <iostream>

using namespace std;

int n, m;
int d = 1;
int arr[20];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = d; i <= n; i++) {
				arr[k] = i;
				d = i;
				func(k + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	func(0);
}