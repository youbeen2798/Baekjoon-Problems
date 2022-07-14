#include <iostream>
#include <map>
using namespace std;

long long n, k;
int num;
int part_sum[200001];
long long cnt = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	map <int, long long>m;

	m[0] = 1;

	for (int i = 1; i <= n; i++) {
		cin >> num;

		part_sum[i] = part_sum[i - 1] + num;

		cnt += m[part_sum[i] - k];

		m[part_sum[i]]++;
	}

	cout << cnt;
}