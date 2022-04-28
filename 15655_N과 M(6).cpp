//N���� �ڿ����� �ڿ��� M�� �־����� ��,
//�Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷�
//N���� �ڿ����� ��� �ٸ� ��
//�� ������ ���������̾�� ��
//������ ���� ������ �����ϴ� ������ ����ؾ� ��
// �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵ�
// �� ������ ������ �����ؼ� ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, end_value;
int d = 1;
int arr[9] = { 0, };
bool isused[10001];

void hello(vector <int> vt) {

	for (int i = 0; i < vt.size(); i++) {
		isused[vt[i]] = false;
	}

}


void func(int k) { //0
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = d; i <= end_value; i++) {
			if (!isused[i]) {
				arr[k] = i;
				isused[i] = 1;
				d = i + 1;
				func(k + 1);
				isused[i] = 0;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	end_value = v[n - 1];

	for (int i = 0; i < 10001; i++) {
		isused[i] = 1; //isused �迭 ��� 1�� �ʱ�ȭ
	}

	hello(v); //hello(5)


	func(0);


}