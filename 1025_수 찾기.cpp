#include <iostream>
#include <cmath>
using namespace std;

char map[10][10]; //���� �Է��� �� ������ �����Ƿ� ���ڷ� �Է¹ޱ�

int n, m;

int answer = -1;  // ���� �������� ���� ���� ���ŵ��� �ʾҴٸ� �ʱⰪ�� -1�� ����Ұ���

bool isoutOfBounds(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return true;
	}
	else {
		return false;
	}
}

bool isSquare(int value) {
	int sq = sqrt(value);

	if (sq * sq == value) { //��Ʈ�� ���� �������� ������ ���� ���� ���ٸ� ������
		return true;
	}
	else {
		return false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); //����� ������(�ʼ�)
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int x = 0; x < n; x++) { //���ڰ� ���۵Ǵ� �ʱ� x��
		for (int y = 0; y < m; y++) { //���ڰ� ���۵Ǵ� �ʱ� y��
			for (int dx = -n; dx < n; dx++) { //���� ��������
				for (int dy = -m; dy < m; dy++) { //���� ��������

					if (dx == 0 && dy == 0) { //���� 
						continue;
					}
					int value = 0;

					int curX = x; //���� x��ǥ ��
					int curY = y; //���� y��ǥ ��

					while (!isoutOfBounds(curX, curY)) { //xy��ǥ�� ����� ����� �ʴ´ٸ�
						value = 10 * value + (map[curX][curY] - '0'); //�� ���� ( 12�� 3�� �߰��Ϸ��� {12*10 + 3 = 123}�� ���� ���� ) 

						if (isSquare(value)) {
							answer = max(value, answer); //���� �� ���� ū ��������� ��ȯ
						}
						curX += dx; //x��ǥ ����
						curY += dy; //y��ǥ ����
					}
				}
			}
		}
	}

	cout << answer;
}

//������ �ִٸ�, 
//���� = ���� - '0';
//���� = ���� + '0'; ���� ���� ��ȯ�� �����ϴ�.
