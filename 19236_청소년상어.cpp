#include <iostream>

using namespace std;

struct fish {
	int x; //��
	int y; //��
	int dir; //����
	bool die; //�׾�����
};

fish fishes[17]; //����� ������ �������
int arr[4][4]; //����� ��ȣ�� �������


int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

int shark_x; //��� ��
int shark_y; //��� ��
int shark_dir; //��� ����
int ans = 0;

void shark_eat(int x, int y) {
	
	int fish_num = arr[x][y]; //����� ��ȣ
	fishes[fish_num].die = true; //����Ⱑ �״´�.
	arr[x][y] = -1; //�迭�� ���� ǥ��
}

void fish_move(int fish_num) {
	//����� ��ȣ fish_num�� ����� ������
	int fish_dir = fishes[fish_num].dir; //����� ����
	int fish_x = fishes[fish_num].x; //����� ��
	int fish_y = fishes[fish_num].y; //����� ��

	for (int dir = fish_dir; dir <= 8; dir++) {
		int nx = fish_x + dx[dir];
		int ny = fish_y + dy[dir];
		
		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
			//���� �ȿ� ���� ��

			int other_fish_num = arr[nx][ny];
			if (!(shark_x == nx && shark_y == ny) && !fishes[other_fish_num].die) {
				//�ڸ� �̵���Ű��
				arr[fish_x][fish_y] = other_fish_num;
				arr[nx][ny] = fish_num;

				fishes[fish_num].x = nx;
				fishes[fish_num].y = ny;
				fishes[fish_num].dir = dir;

				fishes[other_fish_num].x = fish_x;
				fishes[other_fish_num].y = fish_y;
				return;
			}
		}
	}

	for (int dir = 1; dir < fish_dir; dir++) {
		int nx = fish_x + dx[dir];
		int ny = fish_y + dy[dir];

		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
			//���� �ȿ� ���� ��
			int other_fish_num = arr[nx][ny];
			if (!(shark_x == nx && shark_y == ny) && !fishes[other_fish_num].die) {
				//�ڸ� �̵���Ű��
				arr[fish_x][fish_y] = other_fish_num;
				arr[nx][ny] = fish_num;

				fishes[fish_num].x = nx;
				fishes[fish_num].y = ny;
				fishes[fish_num].dir = dir;

				fishes[other_fish_num].x = fish_x;
				fishes[other_fish_num].y = fish_y;
				return;
			}
		}
	}
}
void all_fish_move() {
	
	for (int i = 1; i <= 16; i++) {
		int fish_num = i;
		if (!fishes[fish_num].die) { //����Ⱑ ���� �ʾҴٸ�
			fish_move(fish_num);
		}
	}
}

void fish_move_and_shark_eat(int shark_original_x, int shark_original_y, int fish_eaten_num) {
	//��� ��� ��, ���ݱ��� ���� ����� ��

	ans = max(ans, fish_eaten_num);
	int shark_original_dir = shark_dir;

	
	int copy_arr[4][4];
	fish copy_fishes[17];


	//����� �迭 ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}

	//����� ����
	for (int i = 1; i <= 16; i++) {
		copy_fishes[i] = fishes[i];
	}
	

	int copy_arr2[4][4];
	fish copy_fishes2[17];


	//����� �̵���Ű��
	all_fish_move(); 

	//����� �迭 ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_arr2[i][j] = arr[i][j];
		}
	}

	//����� ����
	for (int i = 1; i <= 16; i++) {
		copy_fishes2[i] = fishes[i];
	}

	for (int i = 1; i <= 3; i++) {
		int nx = shark_x + dx[shark_dir] * i;
		int ny = shark_y + dy[shark_dir] * i;

		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
			int fish_num = arr[nx][ny]; //��Ƹ��� ����� ��ȣ
			if (fish_num != 0) { //����Ⱑ ��Ƹ����� �ʾ��� ��
				fishes[fish_num].die = true;
				arr[nx][ny] = 0;

				shark_dir = fishes[fish_num].dir;
				shark_x = nx; //��� ��ġ �� �ű�
				shark_y = ny; //��� ��ġ �� �ű�


				arr[shark_original_x][shark_original_y] = 0;
				fish_move_and_shark_eat(nx, ny, fish_eaten_num + fish_num);

				//����� �迭 ����
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						arr[i][j] = copy_arr2[i][j];
					}
				}

				//����� ����
				for (int i = 1; i <= 16; i++) {
					fishes[i] = copy_fishes2[i];
				}

				shark_x = shark_original_x; //��� �� ���� ���
				shark_y = shark_original_y; //��� �� ���� ���
				shark_dir = shark_original_dir; //��� ���� ���� ���
			}
		}
	}

	
	//����� �迭 ����
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = copy_arr[i][j];
		}
	}

	//����� ����
	for (int i = 1; i <= 16; i++) {
		fishes[i] = copy_fishes[i];
	}
	
	
}
void solution() {

	//�� ���� ó���� �Դ´�.
	int fish_num = arr[0][0]; //����� ��ȣ
	fishes[fish_num].die = true; //����Ⱑ �״´�.
	arr[0][0] = 0; //�迭�� ���� ǥ��
	shark_x = 0;
	shark_y = 0;
	shark_dir = fishes[fish_num].dir;

	fish_move_and_shark_eat(0, 0, fish_num);


	cout <<  ans << "\n";
}

void input() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			fishes[a]= { i,j,b, false };
			arr[i][j] = a; 
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}