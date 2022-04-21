//���� ������ �̿��Ͽ� ����Ž���� �� ����
//

#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
using namespace std;

vector <int> collect;

void Combination(vector <pair<int, int>> v, vector <pair<int, int>> comb, int r, int index, int depth) {
	//���� v�� �Է¹��� ����
	// ���� comb�� ó���� �� ���ͷ� �����ϸ�, �ϳ��� ������ �ϼ��Ǹ� rũ�⸦ ������ ���Ͱ� �� ����
	// r�� v�߿��� �� ���� �� �̾ƾ� �ϴ����� ��Ÿ���� ��
	// index�� v�κ��� ���Ҹ� ���� �� ���� ���Ҹ� comb�� ���� ��ġ(�ε���)
	// depth�� v�� ��ȸ�ϴ� �ε���
	int sour = 1;
	int bitter = 0;

	if (r == 0)  //depth�� v.size�� �����ϱ� ���� r����ŭ �� ���� ����, comb�� �����Ǿ� ������ �� ��찡 ������ ��
	{
		for (int i = 0; i < comb.size(); i++) {
			sour *= comb[i].first; //�Ÿ��� ���ϰ�
			bitter += comb[i].second; //������ ���Ѵ�.
		}

		collect.push_back(abs(sour - bitter)); // ���� �Ÿ��� ���� ������ ���̸� collect ���Ϳ� ����

	}
	else if (depth == v.size()) // depth�� v.size()�� ����������, ��, v�� ��� ���Ҹ� ��ȸ�ߴµ��� r�� 0�� ���� �ʾ� ������ ���� �� �ϳ��� �� �� ���� ���̽�
	{
		return; //���� �� �ϳ��� �� �� �����Ƿ� return�Ѵ�.
	}
	else
	{
		comb[index].first = v[depth].first;
		comb[index].second = v[depth].second;

		Combination(v, comb, r - 1, index + 1, depth + 1);

		Combination(v, comb, r, index, depth + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	
	vector <pair<int, int>> v(k);

	for (int i = 0; i < k; i++) {
		cin >> v[i].first >> v[i].second;
	}


	for (int r = 1; r <= k; r++) {

		vector <pair<int, int>> comb(r); //������ ������ r�� ���
		Combination(v, comb, r, 0, 0);
	}


	sort(collect.begin(), collect.end()); //�Ÿ��� ������ ���� ������ ���ӵ� �� ���� ���� ���� ������ �ϹǷ� ����
	
	cout << collect[0]; //���� ���� �� ���

	return 0;
}