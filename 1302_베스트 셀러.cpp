#include <iostream>
#include <map>

using namespace std;

int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int result = 0;

    map <string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;
        m[k]++;
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        result = max(result, i->second);
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " " << i->second << "\n";
    }

    /*
    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->second == result) {
            cout << i->first;
            return 0;
        }
    }
    */
}