#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int rnd(float value) { //�ݿø� �Լ� ����
	if (value > 0) 
		value += 0.5;

	else 
		value -= 0.5;
	
	return (int)value;

}


int main() {
	int n;
	cin >> n;

	int* array = new int[n];

	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> array[i];
		sum += array[i];
	}

	float average = sum / double(n);

	cout << rnd(average) << "\n"; //�Ҽ��� ���� ù° �ڸ����� �ݿø�

	
	sort(array, array + n); //�迭 �������� ����


	int median = array[n / 2]; //�߾Ӱ�
	cout << median << "\n";

	int mx = 0;

	vector <pair<int, int>> v; //���ҿ� Ƚ���� ��� ���� ����
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i; j < n; j++) {
			if (array[i] == array[j]) {
				cnt++;
			}
			else {
				break;
			}
		}
//		cout << array[i] << " ����" << cnt << "\n";

		if (cnt > mx) { //Ƚ���� ���� ũ�ٸ�
			v.clear(); //���� ��� ���� ����
			v.push_back(make_pair(array[i], cnt));
			mx = cnt;
		}
		else if (cnt == mx) {
			v.push_back(make_pair(array[i], cnt));
		}

		i += cnt - 1;
	}


	if (v.size() == 1) { //�ֺ��� �ϳ����
		cout << v[0].first << "\n";
	}
	else if (v.size() > 1) { //�ֺ��� 2�� �̻��̶��
		cout << v[1].first << "\n";
	}

	int max = array[n - 1]; //�ִ�
	int min = array[0]; //�ּڰ�
	int range = max - min; //����
	cout << range << "\n"; //����



}
