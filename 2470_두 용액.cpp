#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000000
using namespace std;
vector <int> answer(2);

int main() {

    //���� ������ �z���� �� �����Ͱ� ���� �ݴ� �������� �ٰ����� �������� ������ �������� �˰���

    ios_base::sync_with_stdio(0); //����� ������
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n; //�迭 ���� �����ޱ�

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //�迭 ���� �Է¹ޱ�
    }

    sort(arr, arr + n); //�迭 ����

    int start = 0; // start�� ���� ������
    int end = n - 1; // end�� ������ ������ ����
    int min = INF; //������� 0�� ���� ������� ��

    while (start < end) {
        int sum = arr[start] + arr[end]; //�� ������ ��

        if (min > abs(sum)) { //������ ���ߴ� �� ���� �պ��� �� ���� ���� �������� ���� �ĺ��� �� �� ����

            min = abs(sum); 
            answer[0] = arr[start];
            answer[1] = arr[end];

            if (sum == 0) {
                break;
            }
        }

        if (sum < 0) {
            start++; //0���� �����Ƿ� �� ���� ���� �� Ŀ���� �ϹǷ� start ���� (���� ���� �� ū������ ��ü)
        }

        else {
            end--; //0���� ũ�Ƿ� �� ���� ���� �� �۾ƾ� 0�� �� ��������Ƿ� end�� ���ҽ�Ŵ (ū ���� �� ���� ������ ��ü)
        }
    }

    cout << answer[0] << " " << answer[1];
}