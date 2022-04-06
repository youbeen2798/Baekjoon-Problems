#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];
int cnt[100001];

int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int start = 0; //ó�� �ε���
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