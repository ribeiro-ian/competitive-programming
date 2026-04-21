/*
    SPOJ - Hotels Along the Croatian Coast
    https://www.spoj.com/problems/HOTELS/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a[n];

    for (auto &e : a)
        cin >> e;

    int ans = 0;
    for (int l=0, r=0, sum=0; l < n; l++) {
        while (r < n && sum + a[r] <= m) {
            sum += a[r];
            r++;
        }

        ans = max(ans, sum);
        sum -= a[l];
    }

    cout << ans << "\n";

    return 0;
}