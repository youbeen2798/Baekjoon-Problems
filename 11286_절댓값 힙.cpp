#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0); //����� ������ �ϱ� ����
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<pair<int, int>> pq; //�켱���� ť<����,����>��

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;

        if (input != 0) {
            pq.push({ -abs(input), -input }); //�켱���� ť�� pair.first���� ū ��, pair.second�� ū ������ ���ĵ�
        }
        else {
            if (pq.empty()) {
                cout << "0" << "\n";
            }
            else {
                cout << -pq.top().second << "\n"; //�켱���� ť�� ù��° ������ second�� ��ȯ 
                pq.pop(); //ť�� ù��° ���� ����
            }
        }
    }

    return 0;
}