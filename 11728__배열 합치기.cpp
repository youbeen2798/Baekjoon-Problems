#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void TwoPointer(vector<int> &A, vector<int> &B) {

	sort(A.begin(), A.end()); //TwoPointer�� ù��° ������ ����A ����
	sort(B.begin(), B.end()); //TwoPointer�� �ι�° ������ ����B ����

	int ptrA = 0; //���� A�� ���Ҹ� ����Ű�� ptrA
	int ptrB = 0; //���� B�� ���Ҹ� ����Ű�� ������B

	vector <int> answer(n + m); //����A�� ����B�� ��ģ ���� answer
	int idx = 0; //���� answer�� ����Ű�� ������ idx

	while (ptrA < n && ptrB < m) //�����Ͱ� ���� ������ ���Ҹ� ����ų ������
	{
		if (A[ptrA] < B[ptrB]) { //������A�� ����Ű�� ���� A�� ���Ұ� ������B�� ����Ű�� ���� B�� ���Һ��� �� ������
			answer[idx] = A[ptrA]; // ���� answer�� ������A�� ����Ű�� ����A �� ���� �߰�
			idx++; //���� answer�� ����Ű�� ������A ���������� �� ĭ �̵�
			ptrA++;
		}
		else { //������B�� ����Ű�� ���� B�� ���Ұ� ������A�� ����Ű�� ���� A�� ���Һ��� �� ������
			answer[idx] = B[ptrB];  // ���� answer�� ������B�� ����Ű�� ����A �� ���� �߰�
			idx++; //���� answer�� ����Ű�� ������B ���������� �� ĭ �̵�
			ptrB++;
		}
	}

	while (ptrA < n) {
		answer[idx] = A[ptrA];
		idx++;
		ptrA++;
	}

	while (ptrB < m) {
		answer[idx] = B[ptrB];
		idx++;
		ptrB++;
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
}


int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; // ���� A�� ũ�� >> ���� B�� ũ��

	vector<int> A(n);  //ũ�Ⱑ n�� ����A ����
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector<int> B(m); //ũ�Ⱑ m�� ����B ����
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	TwoPointer(A, B);
}