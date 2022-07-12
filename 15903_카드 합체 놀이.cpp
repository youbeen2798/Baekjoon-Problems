#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; 

	vector <int> v;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k); 
	}


	for (int j = 0; j < m; j++) {
		sort(v.begin(), v.end()); 

		int sum = v[0] + v[1];
		v[0] = sum;
		v[1] = sum;

	}

	int ans = 0;
	for (int k = 0; k < v.size(); k++) {
		ans += v[k];
	}
	cout << ans;
	
}