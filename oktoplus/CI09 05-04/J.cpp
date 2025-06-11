/*
    Codeforces 101853J - Smallest Difference
    https://codeforces.com/gym/101853/problem/J
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, n;

    cin >> tc;
    while (tc--) {
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        for (int l = 0; l < n-1; l++) {
            int next = l+1;
            if (abs(a[next] - a[l]) > 1) continue;

            int r = next;
            while (abs(a[r] - a[l]) <= 1 && abs(a[r]-a[r-1]) <= 1) {
                r++;
            }
            ans = max(ans, r-l);
        }

        cout << max(ans, 1) << '\n';
    }

    return 0;
}