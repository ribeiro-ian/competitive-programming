#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> l(m), r(m), x(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> x[i];
    }

    // iterative segtree: size = 2*n
    vector<int> seg(2 * n);

    // build: initially each knight is "alive" → store its own index
    for (int i = 0; i < n; i++) seg[n + i] = i + 1;
    for (int i = n - 1; i > 0; i--)
        seg[i] = min(seg[i << 1], seg[i << 1 | 1]);

    auto segQuery = [&](int L, int R) {
        int res = INF;
        for (L += n - 1, R += n; L < R; L >>= 1, R >>= 1) {
            if (L & 1) res = min(res, seg[L++]);
            if (R & 1) res = min(res, seg[--R]);
        }
        return res;
    };

    auto segUpdate = [&](int p, int val) {
        p += n - 1;
        seg[p] = val;
        for (p >>= 1; p; p >>= 1)
            seg[p] = min(seg[p << 1], seg[p << 1 | 1]);
    };

    vector<int> ans(n + 1, 0);

    // process fights in reverse
    for (int i = m - 1; i >= 0; i--) {
        int L = l[i], R = r[i], X = x[i];

        while (true) {
            int nxt = segQuery(L, R);
            if (nxt == INF || nxt == X) break;

            ans[nxt] = X;

            // remove nxt from active knights: set it to INF
            segUpdate(nxt, INF);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
