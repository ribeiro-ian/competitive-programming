/*
    UVA 410 - Station Balance
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=351
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
    freopen64("input.txt", "r", stdin);
    freopen64("output.txt", "w", stdout);
#endif
    int c, s, set = 1, x;

    while (scanf("%i %i", &c, &s) != EOF) {
        int v[s];
        double avg = 0, imbalance = 0;

        for (int i = 0; i < s; i++) {
            scanf("%i", &v[i]);
            avg += v[i];
        }
        avg /= c;

        sort(v,v+s);

        printf("Set #%i\n", set++);

        int i;
        for (i = 0; i < s/2; i++) {
            int pair = v[s-i-1- (s % 2 == 1 ? 1 : 0)];
            int chamber = v[i] + pair;

            printf(" %i: %i %i\n", i, v[i], pair);

            imbalance += abs(chamber-avg);
        }
        if (s%2) {
            printf(" %i: %i\n", i, v[s-1]);
            imbalance += abs(v[s-1]-avg);
        }

        printf("IMBALANCE = %.5f\n\n", imbalance);

    }

    return 0;
}
