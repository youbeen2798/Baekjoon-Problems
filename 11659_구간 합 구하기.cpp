#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int* array = new int[n + 1];

	array[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> array[i]; //배열 입력 받기
		array[i] += array[i - 1]; //배열을 누적합으로 변경
	}

	for (int j = 0; j < m; j++) {
		int start, end;
		cin >> start >> end;

		int result = array[end] - array[start - 1]; //누적 합에서 원소 아닌 것들의 누적합 제거
		cout << result << '\n';
	}
}
