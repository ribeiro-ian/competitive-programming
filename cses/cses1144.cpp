/*
    CSES 1143 - Hotel Queries
    https://cses.fi/problemset/task/1143
*/
 
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+1;
vector<int> segtree(4*N);
int n, m, k;
 
void upd(int i, int x) {
    for (segtree[i] -= x; i > 1; i >>= 1)
        segtree[i>>1] = max(segtree[i], segtree[i ^ 1]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; ++i)
        cin >> segtree[i+n];
    for (int i = n-1; i >= 1; --i)
        segtree[i] = max(segtree[i<<1], segtree[i<<1 | 1]);
 
    while (m--) {
        int r; cin >> r;
 
        if (r > segtree[1]) {
            cout << "0 ";
            continue;
        }
 
        int i = 1; // root
        while (i < n) {
            // go left
            if (segtree[i<<1] >= r)
                i = i<<1, cerr << "go left\n";
            // go right
            else if (segtree[i << 1 | 1] >= r)
                i = i<<1 | 1, cerr << "go right\n";
            // not possible
            else
                break;
        }
        cerr << '\n';
        upd(i, r);
        cout << i << ' ';
    }
    cout << '\n';
 
    return 0;
}