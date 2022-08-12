#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int num;
int parent[51];

vector <int> knowing;
vector <vector<int>> party(51);

int Findd(int x) {
	if (parent[x] == x) {
		return x;
	}
	else{
		int result;
		return result = Findd(parent[x]);
	}
}

void Union(int x, int y) {

	int a = Findd(x);
	int b = Findd(y);
	parent[a] = b;

}
void input(){
	cin >> n >> m >> k; //사람의 수 >> 파티의 수 > 진실을 아는 사람의 수


	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < k; i++) {
		cin >> num;
		knowing.push_back(num); //진실을 아는 사람의 수
	}

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;

		for (int j = 0; j < k; j++) {

			int prev = num;
			cin >> num;

			if (j >= 1) {
				Union(prev, num);
			}

			party[i].push_back(num);

		}
		
	}
}

int answer() {

	int res = m;

	for (auto i : party) {

		bool istrue = false;

		for (int j : i) {
			for (int k : knowing) {
				if (Findd(k) == Findd(j)) {
					istrue = true;
					break;
				}
			}
			if (istrue) {
				break;
			}
		}

		if (istrue) {
			res--;
		}
	}

	return res;
}

int main() {
	input();
	cout << Findd(3) << "\n";
	cout << "***: " << answer();
}



