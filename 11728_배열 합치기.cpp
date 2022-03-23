#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
using namespace std;
void TwoPointer(vector<int> &A, vector<int> &B)
{

	sort(A.begin(), A.end()); // A ���� ����
	sort(B.begin(), B.end()); // B ���� ����

	int ptrA = 0; // A ���� ��ġ ����Ű�� ������
	int ptrB = 0; // B ���� ��ġ ����Ű�� ������

	vector <int> answer(n + m); // A�� B ���͸� ��ģ ����
	int idx = 0;

	while (ptrA < n && ptrB < m) { //�Ѵ� ����Ű�� �����Ͱ� ���� ������
		if (A[ptrA] < B[ptrB]) {
			answer[idx] = A[ptrA]; // A ���� ���Ҹ� answer ���Ϳ� 
			idx++;
			ptrA++;
		}
		else {
			answer[idx] = B[ptrB]; // B ���� ���Ҹ� answer
			idx++;
			ptrB++;
		}
	}

	while (ptrA < n) { // A���͸� �� ��ȸ���� ���ߴٸ�
		answer[idx] = A[ptrA]; 
		idx++;
		ptrA++;
	}
	while (ptrB < m) { // B���͸� �� ��ȸ���� ���ߴٸ�
		answer[idx] = B[ptrB];
		idx++; //answer ���� ������ �̵�
		ptrB++; //B ���� ������ �̵�
	}

	for (int i : answer)
		cout << i << " "; //answer ��� ���� ���� ���
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; //���� A�� ũ�� >> ���� B�� ũ��

	vector <int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	vector <int> B(m);
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	TwoPointer(A, B);
}