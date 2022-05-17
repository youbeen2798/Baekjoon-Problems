#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int n;

vector <pair<int, int>> v;

void start() {

	v.push_back(make_pair(1, 0)); //v[0]
	v.push_back(make_pair(0, 1)); //v[1]

	for (int i = 2; i <= 40; i++) {
		int x = v[i - 2].first + v[i - 1].first;
		int y = v[i - 2].second + v[i - 1].second;
		v.push_back(make_pair(x, y));
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	start();
		
	while (T--) {
		cin >> n;
		cout << v[n].first << " " << v[n].second << "\n";
	}
	
}