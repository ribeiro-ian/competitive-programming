/*
    Codeforces 1469B - Red and Blue
    https://codeforces.com/problemset/problem/1469/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int tc, n, m;

    scanf("%i", &tc);

    while (tc--) {
        scanf("%i", &n);
        vector <int> r(n), r_pref(n+1);
        for (int i = 0; i < n; i++) {
            scanf("%i", &r[i]);
            r_pref[i+1] = r_pref[i] + r[i];
        }
        
        scanf("%i", &m);
        vector <int> b(m), b_pref(m+1);
        for (int i = 0; i < m; i++) {
            scanf("%i", &b[i]);
            b_pref[i+1] = b_pref[i] + b[i];
        }

        printf("%i\n", *max_element(r_pref.begin(), r_pref.end()) +
                            *max_element(b_pref.begin(), b_pref.end()));

    }

    return 0;
}