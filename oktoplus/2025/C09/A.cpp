/*
    Codeforces 2091A - Olympiad Date
    https://codeforces.com/problemset/problem/2091/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tc, n, x;
    cin >> tc;

    while (tc--) {
        int cnt[10] = {0};
        cin >> n;

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            cin >> x;

            cnt[x]++;
            if (cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1) {
                ans = min(ans, i);
            }
        }

        cout << (ans != INT_MAX ? ans : 0) << endl;
    }

    return 0;
}