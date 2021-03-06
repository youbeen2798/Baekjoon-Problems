#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];
int cnt[100001];

int main() {
	ios_base::sync_with_stdio(0); //입출력 빠르게
	cin.tie(0);
	cout.tie(0);

	int start = 0; //처음 인덱스
	int answer = 0;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;

		while (cnt[arr[i]] > k) {
			cnt[arr[start++]]--;
		}

		answer = max(answer, i - start + 1);
	}

	cout << answer;

}