/*
    Codeforces 2091A - Olympiad Date
    https://codeforces.com/contest/2091/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int tc, n, x;
    cin >> tc;

    while (tc--) {
        cin >> n;

        int v[10] = {0};

        int ans = 0; bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> x;

            v[x] += 1;

            if (v[1] >= 1 && v[2] >= 2 && v[0] >= 3 && v[5] >= 1 && v[3] >= 1 && !flag) {
                ans = i+1;
                flag = true;
            }
        }

        printf("%i\n", ans);
    }

    return 0;
}