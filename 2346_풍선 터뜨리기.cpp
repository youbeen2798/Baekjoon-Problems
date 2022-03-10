#include <iostream>
#include <utility>
#include <deque>

using namespace std;

deque <pair<int, int>> dq; //�ΰ��� ���� ���� �ϳ��� ����
int main() {
    ios_base::sync_with_stdio(0); //����� �ð� ���̱�
    cin.tie(0); 
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        dq.push_back(make_pair(tmp, i + 1)); //�ε����� ���� �ϳ��� ��� ����
    }

    while (true) {
        int cnt = dq.front().first;
        cout << dq.front().second << " ";
        dq.pop_front(); //ù��° ���Ұ� ����

        if (dq.empty()) { //���� ��������� ����
            break;
        }
        else {
            if (cnt > 0) {
                for (int i = 0; i < cnt - 1; i++) {
                    dq.push_back(dq.front()); //���� ���� ���Ҹ� �����Ͽ� �ڷ� ����
                    dq.pop_front(); //���� ���� ���� ����
                }
            }
            else {
                for (int i = 0; i < abs(cnt); i++) {
                    dq.push_front(dq.back()); //���� ���� ���Ҹ� �����Ͽ� ������ ����
                    dq.pop_back(); //���� ���� ���� ����
                }
            }
        }
    }

}