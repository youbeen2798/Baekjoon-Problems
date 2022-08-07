#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[10000];

int get_num(int a, int b, int c, int d) {

	int num1 = 1000 * a + 100 * b + 10 * c + 1*d;
	int num2 = 1000 * b + 100 * c + 10 * d + 1 * a;
	int num3 = 1000 * c + 100 * d + 10 * a + 1 * b;
	int num4 = 1000 * d + 100 * a + 10 * b + 1 * c;
	return min({ num1, num2, num3, num4 });
}

void get_all_num() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int m = 1; m <= 9; m++) {
				for (int k = 1; k <= 9; k++) {
					visited[get_num(i, j, m, k)] = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int ans = get_num(a, b, c, d);

	get_all_num();

	int answer = 0;

	for (int i = 1111; i <= ans; i++) {
		if (visited[i]) {
			answer++;
		}
	}

	cout <<  answer << "\n";


}