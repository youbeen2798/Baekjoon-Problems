#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000000
using namespace std;
vector <int> answer(2);

int main() {

    //¾çÂÊ ³¡¿¡¼­ ­z¶óÇÑ µÎ Æ÷ÀÎÅÍ°¡ ¼­·Î ¹İ´ë ¹æÇâÀ¸·Î ´Ù°¡¿ö¼­ Á¼ÇôÁö´Â ÇüÅÂÀÇ ÅõÆ÷ÀÎÅÍ ¾Ë°í¸®Áò¤¤

    ios_base::sync_with_stdio(0); //ÀÔÃâ·Â ºü¸£°Ô
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n; //¹è¿­ ¿ø¼Ò °³¼ö¹Ş±â

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //¹è¿­ ¿ø¼Ò ÀÔ·Â¹Ş±â
    }

    sort(arr, arr + n); //¹è¿­ Á¤·Ä

    int start = 0; // startÀº ¿ŞÂÊ ³¡¿¡¼­
    int end = n - 1; // end´Â ¿À¸¥ÂÊ ³¡¿¡¼­ ½ÃÀÛ
    int min = INF; //ÇöÀç±îÁö 0¿¡ °¡Àå °¡±î¿ü´ø ÇÕ

    while (start < end) {
        int sum = arr[start] + arr[end]; //µÎ ¿ø¼ÒÀÇ ÇÕ

        if (min > abs(sum)) { //±âÁ¸¿¡ ±¸Çß´ø µÎ ¼öÀÇ ÇÕº¸´Ù ´õ ÀÛÀº ÇÕÀÌ ³ª¿ÔÀ¸´Ï Á¤´ä ÈÄº¸°¡ µÉ ¼ö ÀÖÀ½

            min = abs(sum); 
            answer[0] = arr[start];
            answer[1] = arr[end];

            if (sum == 0) {
                break;
            }
        }

        if (sum < 0) {
            start++; //0º¸´Ù ÀÛÀ¸¹Ç·Î µÎ ¼öÀÇ ÇÕÀÌ ´õ Ä¿Á®¾ß ÇÏ¹Ç·Î start Áõ°¡ (ÀÛÀº °ªÀ» ´õ Å«°ªÀ¸·Î ´ëÃ¼)
        }

        else {
            end--; //0º¸´Ù Å©¹Ç·Î µÎ ¼öÀÇ ÇÕÀÌ ´õ ÀÛ¾Æ¾ß 0¿¡ ´õ °¡±î¿öÁö¹Ç·Î end¸¦ °¨¼Ò½ÃÅ´ (Å« °ªÀ» ´õ ÀÛÀº °ªÀ¸·Î ´ëÃ¼)
        }
    }

    cout << answer[0] << " " << answer[1];
}