#include <iostream>
#include <algorithm>
using namespace std;

char a;
int b;
int n;
string st;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	pair<char, int> king = make_pair(a, b); //�� ��ġ
	cin >> a >> b;
	pair<char, int> stone = make_pair(a, b); //�� ��ġ

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st;
		if (st == "R") {
			king.first++; //���������� ��ĭ �̵�
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.first++; //���� ���������� ��ĭ �̵�
				cnt++; //���� �̵��ߴٴ� ����
			}

			//Ȥ�� ���̳� ���� ������ �����ٸ�
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first--; //�� ���ڸ��� ����ġ(�������� ��ĭ�̵�)
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.first--; //���� �������� ����ġ(�������� ��ĭ�̵�)
				}
				continue;
			}

		}
		else if (st == "L") {
			king.first--; //�������� ��ĭ �̵�
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.first--;
				cnt++; //���� �̵��ߴٴ� ����
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first++; //�� ���ڸ��� ����ġ(���������� ��ĭ�̵�)
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.first++; //���� �������� ����ġ(���������� ��ĭ�̵�)
				}
				continue;
			}
		}
		else if (st == "B") {
			king.second--; //�Ʒ��� ��ĭ �̵�
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.second--;
				cnt++; //���� �̵��ߴٴ� ����
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.second++; //�� ���ڸ��� ����ġ(���� ��ĭ�̵�)
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.second++; //���� ���ڸ��� ����ġ(���� ��ĭ �̵�)
				}
				continue;
			}
		}
		else if (st == "T") {
			king.second++; //���� ��ĭ �̵�
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.second++;
				cnt++; //���� �̵��ߴٴ� ����
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.second--; //�� ���ڸ��� ����ġ(�Ʒ��� ��ĭ �̵�)
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.second--; //���� ���ڸ��� ����ġ(�Ʒ��� ��ĭ �̵�)
				}
				continue;
			}
		}
		else if (st == "RT") {
			king.first++; //���������� ��ĭ�̵�
			king.second++; //���� ��ĭ �̵�
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.first++; //�� ���������� ��ĭ�̵�
				stone.second++; //�� ���� ��ĭ�̵�
				cnt++; //���� �̵��ߴٴ� ����
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first--;
				king.second--;
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.first--;; //�� ���ڸ��� ����ġ(�������� ��ĭ �̵�)
					stone.second--; //�� ���ڸ��� ����ġ(�Ʒ��� ��ĭ�̵�)
				}
				continue;
			}
		}
		else if (st == "LT") {
			king.first--;
			king.second++;
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.first--;
				stone.second++;
				cnt++; //���� �̵��ߴٴ� ����
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first++;
				king.second--;
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.first++;
					stone.second--;
				}
				continue;
			}
		}
		else if (st == "RB") {
			king.first++;
			king.second--;
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.first++;
				stone.second--;
				cnt++; //���� �̵��ߴٴ� ����
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first--;
				king.second++;
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.first--;
					stone.second++;
				}
				continue;
			}
		}
		else if (st == "LB") {
			king.first--;
			king.second--;
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //���� ���� ���̶��
				stone.first--;
				stone.second--;
				cnt++; //���� �̵��ߴٴ� ����
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first++;
				king.second++;
				if (cnt == 1) { //Ȥ�� ���� �̵��߾��ٸ�
					stone.first++;
					stone.second++;
				}
				continue;
			}
		}
	}


	cout << king.first << king.second << "\n";
	cout << stone.first << stone.second << "\n";

}