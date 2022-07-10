#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n; 

	vector <int> v;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	
	vector <int> vt;
	int num = 0;
	int num_idx = 0;
	for (int i = v.size() - 1; i > 0; i--) {
		if (v[i] > v[i - 1]) {
			vt.push_back(v[i]);
		}
		else {
			vt.push_back(v[i]);
			num = v[i - 1];
			num_idx = i - 1;
			break;
		}
	}

	if (num == 0) {
		cout << -1;
		exit(0);
	}

	int mx = 0;
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i] < num && vt[i]>mx) {
			mx = vt[i];
		}
	}
	
	vt.push_back(num);
	vt.erase(remove(vt.begin(), vt.end(), mx),vt.end());


	v[num_idx] = mx;

	for (int i = 0; i <= num_idx; i++) {
		cout << v[i] << " ";
	}

	sort(vt.rbegin(), vt.rend());

	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i] << " ";
	}
}