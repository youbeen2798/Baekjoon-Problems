#include <iostream>

using namespace std;

string A;
string B;

void solution() {

	int diff = B.size() - A.size(); //글자 수 차이

	int min_diff = 51;
	for (int i = 0; i <= diff; i++) {
		int tmp_diff = 0;
		for (int j = i, k = 0; j < i + A.size(); j++, k++)
		{
			if (B[j] != A[k]) {
				tmp_diff++;
			}
			cout << j << " ";
		}
		cout << "tmp_diff: " << tmp_diff << "\n";
		min_diff = min(min_diff, tmp_diff);
		cout << "\n";
	}
	cout << min_diff;
}

void input() {
	cin >> A >> B;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}