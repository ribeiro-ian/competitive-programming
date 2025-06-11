/*
    CSES 1624 - https://cses.fi/problemset/task/1624
    https://cses.fi/problemset/task/1624
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int n = 8, DIAG = 15;
vector <int> col(n, 0), diag1(DIAG, 0), diag2(DIAG, 0);
vector <vector <bool>> valid (n, vector <bool> (n, true));
ll cnt;

void search(int y) {
    if (y == n) {
        cnt++;
        return;
    }
    for (int x = 0; x < n; ++x) {
        // y = row; x = col
        if (col[x] || diag1[x+y] || diag2[x-y+n-1] || !valid[y][x]) continue;
 
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            valid[i][j] = (c == '.');
        }
    }

    cnt = 0;
    search(0);
    cout << cnt << '\n';

    return 0;
}