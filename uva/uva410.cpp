/*
    UVA 410 - Station Balance
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=351
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int c, s, set = 1, x;

    while (cin >> c >> s) {
        int n = 2*c;
        int v[n] = {0};
        double avg = 0, imbalance = 0;

        for (int i = 0; i < s; i++) {
            cin >> v[i];
            avg += v[i];
        }
        avg /= c;

        sort(v,v+n);

        printf("Set #%i\n", set++);

        for (int i = 0; i < c; i++) {
            int chamber = v[i] + v[n-1-i];
            
            cout << " " << i << ":";
            if (v[i]) cout << " " << v[i];
            if (v[n-1-i]) cout << " " << v[n-1-i];
            cout << "\n";

            imbalance += abs(chamber-avg);
        }

        printf("IMBALANCE = %.5f\n\n", imbalance);
    }

    return 0;
}