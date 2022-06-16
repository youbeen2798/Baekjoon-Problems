#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, k;
vector <string> card;
set <string> cardSet;
vector <string> tmp;
int ck[11];

void dfs(int depth) {
	if (depth == k) {
		string c;
		for (auto t : tmp) {
			c += t;
		}
		cardSet.insert(c);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (ck[i]) continue;
		ck[i] = 1;
		tmp.push_back(card[i]);
		dfs(depth + 1);
		tmp.pop_back();
		ck[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int sum = 0;
	while(n--){
		int k;
		cin >> k;
		sum += k;
	}
	cout << sum;
}