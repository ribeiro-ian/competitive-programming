#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a[4];
    for (auto &e : a)
        cin >> e;
    
    for (int i=0; i <4; i++) {
        int x = a[i];

        if (i==0) {
            bool flag = true;
            for (int j = 1; j < 3; j++) {
                if (a[j+1]-a[j] != 1) {
                    flag = false;
                }
            }
            if (flag) {
                cout << 1 << "\n";
                return 0;
            }
        }

        if (i == 1) {
            if (a[0] == a[2] && a[3] == a[2]+1) {
                cout << 2 << "\n";
                return 0;
            }
        }
        if (i == 2) {
            if (a[1] == a[3] && a[0] == a[1]+1) {
                cout << 3 << "\n";
                return 0;
            }

        }
        if (i== 3) {
            bool flag = true;
            for (int j = 2; j >= 1; j--) {
                if (abs(a[j]-a[j-1]) != 1) {
                    flag = false;
                }
                if (flag) {
                    cout << 4 << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}