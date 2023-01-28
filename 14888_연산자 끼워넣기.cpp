#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[12];

int operators[12];
int first_num;

int plus_num, minus_num, ���ϱ�_num, ������_num;
//���ϱ�, ����, ���ϱ�, ������
// 1 , 2 , 3 , 4

vector<int> v;
vector<long> answers;

void mini_solution(vector<int> v) {

	int idx = 0;
	for (auto tmp : v) {
		operators[idx++] = tmp;
	}

//	cout << "n: " << n << "\n";

//	cout << first_num << " ";

	long result = first_num;
	for (int i = 0; i < n - 1; i++) {
		if (operators[i] == 1) { //�����̸�
			result += arr[i];
		}
		else if (operators[i] == 2) { //�����̸�
			result -= arr[i];
		}
		else if (operators[i] == 3) { //�����̸�
			result *= arr[i];
		}
		else { //�������̸�
			if (result < 0) { //������
				result = abs(result) / arr[i] * -1;
				continue;
			}
			result = result / arr[i];
		}
//		cout << operators[i] << " " <<  arr[i] << " ";
	}

	answers.push_back(result);
//	cout << "##result: " << result << "\n";
//	cout << "\n";
}

void solution() {

	int idx = 0;
	
	for (int i = 0; i < plus_num; i++) {
		v.push_back(1);
	}

	for (int i = 0; i < minus_num; i++) {
		v.push_back(2);
	}

	for (int i = 0; i < ���ϱ�_num; i++) {
		v.push_back(3);
	}

	for (int i = 0; i < ������_num; i++) {
		v.push_back(4);
	}

	sort(v.begin(), v.end());

	do {
		mini_solution(v);
	} while (next_permutation(v.begin(), v.end()));

	sort(answers.begin(), answers.end());
	cout << answers[answers.size() - 1] << "\n";
	cout << answers[0];
}

void input() {

	cin >> n;

	cin >> first_num;
	for (int i = 0; i < n - 1; i++) {
		cin >> arr[i];
	}

	cin >> plus_num >> minus_num >> ���ϱ�_num >> ������_num;
}
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}