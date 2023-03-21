#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dice_nums[10];
int is_horse[8][6];
int map[8][6] =
{
{-1,2,4,6,8,10},
{-1,12,14,16,18,20},
{-1,22,24,26,28,30},
{-1,32,34,36,38,40},
{-1,13,16,19,25,-1}, //4(3)
{-1,22,24,25,-1,-1}, //5(3)
{-1,28,27,26,25,-1}, //6(3)
{-1,30,35,40,-1,-1}
};


struct horse_position {
    int x;
    int y;
    bool dead;
};

vector<int> v;

horse_position horses[5];
int ans = 0;
int total_score = 0;
int tmp_num = 0;

void horse_move(int times) {

    if (times == 10) {
        ans = max(total_score, ans);
        return;
    }

    int dice_num = dice_nums[times]; //주사위 숫자

    for (int i = 1; i <= 4; i++) {
        if (!horses[i].dead) {
           
            int origin_x = horses[i].x;
            int origin_y = horses[i].y;

            if (0 <= origin_x && origin_x <= 2) {
                if (origin_y + dice_num > 5) {
                    horses[i].x++;
                    //4에서 3번 더하면 7

                    int diff = 5 - origin_y; //1
                    horses[i].y = dice_num - diff;
                }
                else {
                    horses[i].y += dice_num;
                }
            }
            else if (origin_x == 3) {
                if (origin_y + dice_num > 5) {
                    horses[i].dead = true;
                }
                else {
                    horses[i].y += dice_num;
                }
            }
            else if (origin_x == 4 || origin_x == 6) {

                int diff = 4 - horses[i].y; //현재 위치

                if (dice_num - diff > 3) {
                    horses[i].dead = true; //말 죽음
                }
                else if (origin_y + dice_num > 4) {
                    horses[i].x = 7;
                    horses[i].y = dice_num - diff;
                }
                else {
                    horses[i].y += dice_num;
                }
            }
            else if (origin_x == 5) {

                int diff = 3 - horses[i].y; //diff = 2
                //dice_num = 3

                if (dice_num - diff > 3) {
                    horses[i].dead = true; //말 죽음
                }
                else if (origin_y + dice_num > 3) {
                    horses[i].x = 7;
                    horses[i].y = dice_num - diff;
                }
                else {
                    horses[i].y += dice_num;
                }
            }
            else if (origin_x == 7) {
                if (dice_num + origin_y >= 4) {
                    horses[i].dead = true;
                }
                else {
                    horses[i].y += dice_num;
                }
            }

            int plus_score = map[horses[i].x][horses[i].y];

            if (plus_score == 20) {
                horses[i].x = 5;
                horses[i].y = 0;
            }
            else if (plus_score == 10) {
                horses[i].x = 4;
                horses[i].y = 0;
            }
            else if (horses[i].x == 2 && horses[i].y == 5) {
                horses[i].x = 6;
                horses[i].y = 0;
            }
            else if (plus_score == 25) {
                horses[i].x = 7;
                horses[i].y = 0;
            }
            else if (plus_score == 40) {
                horses[i].x = 7;
                horses[i].y = 3;
            }



            if (!is_horse[horses[i].x][horses[i].y] && !horses[i].dead) {
                //이동을 마치는 칸에 말이 없다면

                is_horse[horses[i].x][horses[i].y] = i;
                is_horse[origin_x][origin_y] = 0;

                total_score += plus_score;
       
                horse_move(times + 1);
                total_score -= plus_score;

                is_horse[origin_x][origin_y] = i;
                is_horse[horses[i].x][horses[i].y] = 0;

                //원래대로 말 돌려놓기
                horses[i].x = origin_x;
                horses[i].y = origin_y;
                horses[i].dead = false;
            }
            else if (horses[i].dead) {
                //말이 죽었다면

                is_horse[origin_x][origin_y] = 0;
            
                horse_move(times + 1);

                //원래대로 말 돌려놓기
                is_horse[origin_x][origin_y] = i;

                horses[i].x = origin_x;
                horses[i].y = origin_y;
                horses[i].dead = false;
            }
            else {
                //이동을 마치는 칸에 말이 있다면

 

                horses[i].x = origin_x;
                horses[i].y = origin_y;
                horses[i].dead = false;
            }
        }
    }
}

void solution() {

    for (int i = 1; i <= 4; i++) {
        horses[i] = { 0,0,false };
    }

    horse_move(0);

    cout <<  ans << "\n";
}
void input() {

    for (int i = 0; i < 10; i++) {
        cin >> dice_nums[i];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solution();
}