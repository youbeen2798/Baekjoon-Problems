#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second; //ù��° ��ǥ�� ���ٸ�, 2��° ��ǥ�� �����ϴ� ������ ����
	}
	else {
		return a.first < b.first; //ù ��° ��ǥ�� �����ϴ� ������ ����
	}
}


int main() {

	int n;
	cin >> n;

	vector <pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), compare); //���� ����
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

}