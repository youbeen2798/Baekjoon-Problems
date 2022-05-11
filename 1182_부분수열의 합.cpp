#include <iostream>

using namespace std;

int N, S;
int arr[20];
/*
void numOfSubset(int idx, int sum) {
	sum += arr[idx];

	if (sum == S)
		result;

	//해당 원소를 넣은 경우
	numOfSubset(idx + 1, sum);

	//해당 원소를 넣지 않은 경우
	numOfSubset(idx + 1, sum - arr[idx]);

}
*/
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 20; i++) {
		cout << arr[i];
	}

}