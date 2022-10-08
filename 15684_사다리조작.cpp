#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int n, m, h;

vector <pair<int, int>> v;
set <pair<int, int>> s1;
set <pair<int, int>> s2;

bool answer = false;

void add(vector<pair<int, int>> comb, int r) { //comb = {1,5}
	
	bool connected[35][15]; //���μ� ����: h // ���μ� ���� : n
	
	memset(connected, false, sizeof(connected));

	for (auto it = s1.begin(); it != s1.end(); it++) {
		int x = (*it).first;
		int y = (*it).second;

		connected[x][y] = true; //�����
	}

	for (int i = 0; i < comb.size(); i++) {
		int x = comb[i].first;
		int y = comb[i].second;

		connected[x][y] = true; //�����
	}

	int cnt = 0;

	for (int now_col = 1; now_col <= n; now_col++) {

		int now_col2 = now_col;
		int now_row = 1; //1�� 1��

		bool check = false;


		while (true) {

			if (now_col2 == 1) { //���μ��� 1�̸�
				for (int i = now_row; i <= h; i++) { //���μ��� ����
					if (connected[i][now_col2]) { //[1][1]
						now_col2++; //�� �ϳ� ���������� �̵�

							now_row = i + 1;
						break;
					}
					else {
						now_row++;
					}
				}
			}
			else if (now_col2 == n) { //���μ��� �������̶��
				for (int i = now_row; i <= h; i++) { // i = 5 ~ 6
					if (connected[i][now_col2 - 1]) { //����
						now_col2--;
						now_row = i + 1;
						break;
					}
					else {
						now_row++;
					}
				}
			}
			else { //���μ��� �߰��̸� (now_col = 4, now_row = 3) //���μ��� 2

				for (int i = now_row; i <= h; i++) {
					if (connected[i][now_col2 - 1]) { //����
						now_col2--;
						now_row = i + 1;

						break;
					}
					else if (connected[i][now_col2]) { //������ [3][2]
						now_col2++; //���߰�
						now_row = i + 1;
						break;
					}
					else {
							now_row++;
					}
				}
			}

			if (now_row == h + 1) { //now_row = 6
				if (now_col != now_col2) {
					check = true;
					break;
				}
				else {
					cnt++;

					if (cnt == n) {
						answer = true;
						cout <<  r << "\n";
						return;
					}
					break;
				}	
			}
		}

		//while��, for�� ��
		if (check) { //ó���� �������� ���� �ʴ´ٸ� ����
			break;
		}
	}
}

void Combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int index, int depth, int k) {
	
	if (r == 0) {
		if (!answer) {
			add(comb, k);
		}
		else {
			return;
		}
	}
	else if (arr.size() == depth) {
		return;
	}
	else{
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1, k); //�ش� ���Ҹ� ������ ���

		Combination(arr, comb, r, index, depth + 1, k); //�ش� ���Ҹ� �������� ���� ���
	}
}
void input() {
	cin >> n >> m >> h; 
	//���μ� ����, ���μ� ����, ���μ����� ���μ��� ���� �� �ִ� ��ġ�� ����

	for (int i = 0; i < m; i++) {
		int a;
		int b;
		cin >> a >> b; //b�� ���μ��� b+1�� ���μ��� a�� ���� ��ġ���� ����
		s1.insert({ a,b }); //�̹� �����ϴ� ���μ�
	}


	//���� ���μ�(�����ϴ� ���μ� �翷 ���μ�)
	for (auto it = s1.begin(); it != s1.end(); it++) {

		int x = (*it).first;
		int y = (*it).second;

		if (y == 1) { //���� ���� �ִٸ�
			s2.insert({ x,2 }); //������ �Ѱ���
		}
		else if (y == n - 1) { //������ ���� �ִٸ�
			s2.insert({ x, n -  2 }); //���� �Ѱ���
		}
		else { //���� ���� ������ �� �� �� �ƴ϶��
			
			s2.insert({ x, y - 1 });
			s2.insert({ x,y + 1 });
		}
	}


	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if ( (s1.find({ i,j }) == s1.end()) && (s2.find({i,j}) == s2.end())) { //�̹� �����ϴ� ���μ��� �ƴ϶��
				v.push_back({ i,j }); //���μ� �߰�
			}
		}
	}


	int r0 = 0;

	vector <pair<int, int>> comb0(r0);
	Combination(v, comb0, r0, 0, 0, r0);

	if (!answer) {
		int r1 = 1;
		vector <pair<int, int>> comb1(r1);
		Combination(v, comb1, r1, 0, 0, r1);
	}
	
	if (!answer) {
		int r2 = 2;
		vector<pair<int, int>> comb2(r2);
		Combination(v, comb2, r2, 0, 0, r2);
	}

	if (!answer) {
		int r3 = 3;
		vector<pair<int, int>> comb3(r3);
		Combination(v, comb3, r3, 0, 0, r3);
	}

	if (!answer) {
		cout << "-1";
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();


}