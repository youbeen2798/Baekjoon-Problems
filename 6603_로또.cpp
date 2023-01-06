#include <iostream>
#include <vector>
using namespace std;
//int ans = 0;

void combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
	if (r == 0) {
//		ans++;
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		comb[index] = arr[depth];
		//»ÌÀº °æ¿ì
		combination(arr, comb, r - 1, index + 1, depth + 1);
		//»ÌÁö ¾ÊÀº °æ¿ì
		combination(arr, comb, r, index, depth + 1);
	}
}

void input() {
	while (true) {
		int num;
		vector<int> v;
		
		cin >> num;
		if (num == 0) {
			break; 
		}
		for (int i = 0; i < num; i++) {
			int v_num;
			cin >> v_num;
			v.push_back(v_num);
		}
		
//		ans = 0;
		vector<int> comb(6);
		combination(v, comb, 6, 0, 0);
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}