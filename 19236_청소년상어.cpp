#include <iostream>

using namespace std;

struct fish {
	int x; //행
	int y; //열
	int dir; //방향
	bool die; //죽었는지
};

fish fishes[17]; //물고기 정보가 들어있음
int arr[4][4]; //물고기 번호가 들어있음


int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

int shark_x; //상어 행
int shark_y; //상어 열
int shark_dir; //상어 방향
int ans = 0;

void shark_eat(int x, int y) {
	
	int fish_num = arr[x][y]; //물고기 번호
	fishes[fish_num].die = true; //물고기가 죽는다.
	arr[x][y] = -1; //배열에 죽은 표시
}

void fish_move(int fish_num) {
	//물고기 번호 fish_num인 물고기 움직임
	int fish_dir = fishes[fish_num].dir; //물고기 방향
	int fish_x = fishes[fish_num].x; //물고기 행
	int fish_y = fishes[fish_num].y; //물고기 열

	for (int dir = fish_dir; dir <= 8; dir++) {
		int nx = fish_x + dx[dir];
		int ny = fish_y + dy[dir];
		
		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
			//범위 안에 들어올 때

			int other_fish_num = arr[nx][ny];
			if (!(shark_x == nx && shark_y == ny) && !fishes[other_fish_num].die) {
				//자리 이동시키기
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
			//범위 안에 들어올 때
			int other_fish_num = arr[nx][ny];
			if (!(shark_x == nx && shark_y == ny) && !fishes[other_fish_num].die) {
				//자리 이동시키기
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
		if (!fishes[fish_num].die) { //물고기가 죽지 않았다면
			fish_move(fish_num);
		}
	}
}

void fish_move_and_shark_eat(int shark_original_x, int shark_original_y, int fish_eaten_num) {
	//상어 행과 열, 지금까지 먹은 물고기 수

	ans = max(ans, fish_eaten_num);
	int shark_original_dir = shark_dir;

	
	int copy_arr[4][4];
	fish copy_fishes[17];


	//물고기 배열 저장
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}

	//물고기 저장
	for (int i = 1; i <= 16; i++) {
		copy_fishes[i] = fishes[i];
	}
	

	int copy_arr2[4][4];
	fish copy_fishes2[17];


	//물고기 이동시키기
	all_fish_move(); 

	//물고기 배열 저장
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_arr2[i][j] = arr[i][j];
		}
	}

	//물고기 저장
	for (int i = 1; i <= 16; i++) {
		copy_fishes2[i] = fishes[i];
	}

	for (int i = 1; i <= 3; i++) {
		int nx = shark_x + dx[shark_dir] * i;
		int ny = shark_y + dy[shark_dir] * i;

		if (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
			int fish_num = arr[nx][ny]; //잡아먹힐 물고기 번호
			if (fish_num != 0) { //물고기가 잡아먹히지 않았을 때
				fishes[fish_num].die = true;
				arr[nx][ny] = 0;

				shark_dir = fishes[fish_num].dir;
				shark_x = nx; //상어 위치 행 옮김
				shark_y = ny; //상어 위치 열 옮김


				arr[shark_original_x][shark_original_y] = 0;
				fish_move_and_shark_eat(nx, ny, fish_eaten_num + fish_num);

				//물고기 배열 저장
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						arr[i][j] = copy_arr2[i][j];
					}
				}

				//물고기 저장
				for (int i = 1; i <= 16; i++) {
					fishes[i] = copy_fishes2[i];
				}

				shark_x = shark_original_x; //상어 행 원래 대로
				shark_y = shark_original_y; //상어 열 원래 대로
				shark_dir = shark_original_dir; //상어 방향 원래 대로
			}
		}
	}

	
	//물고기 배열 저장
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = copy_arr[i][j];
		}
	}

	//물고기 저장
	for (int i = 1; i <= 16; i++) {
		fishes[i] = copy_fishes[i];
	}
	
	
}
void solution() {

	//상어가 제일 처음에 먹는다.
	int fish_num = arr[0][0]; //물고기 번호
	fishes[fish_num].die = true; //물고기가 죽는다.
	arr[0][0] = 0; //배열에 죽은 표시
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