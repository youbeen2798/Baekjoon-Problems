#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {

	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector <int> vt(n);

	vt = v; //���� ��ü ���� ����
//	copy(v.begin(), v.end(), vt.begin());

	sort(vt.begin(), vt.end()); //���� ����
	vt.erase(unique(vt.begin(), vt.end()), vt.end()); //���� �ߺ� ���� ����


	for (int i = 0; i < n; i++) {
		int idx = lower_bound(vt.begin(), vt.end(), v[i]) - vt.begin(); //���� Ư������ ��ġ �ε��� ã��(find�� �ϸ� �ð��ʰ�)
		cout << idx << " ";
	}
}