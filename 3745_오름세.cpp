#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> lis;

void print() {
	cout << "############";
	for (int i = 0; i < lis.size(); i++) {
		cout << lis[i] << " ";
	}
	cout << "\n";
}
void input() {

	while (cin >> n) {
		lis.clear();
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			if (lis.empty() || lis.back() < num) {
				lis.push_back(num);
			}
			else {
				int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
				lis[idx] = num;
			}
		}
		cout << lis.size() << "\n";

	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}