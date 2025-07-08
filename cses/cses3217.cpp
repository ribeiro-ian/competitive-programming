#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector <int>> grid;
ll n;
void rec(int i, int j, int v) {
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] < v) return;

    grid[i][j] = v;

    v++;
    rec(i+2, j+1, v);
    rec(i+2, j-1, v);
    rec(i-2, j+1, v);
    rec(i-2, j-1, v);

    rec(i+1, j+2, v);
    rec(i-1, j+2, v);
    rec(i+1, j-2, v);
    rec(i-1, j-2, v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    grid.assign(n, vector<int>(n,n*n));

    grid[0][0] = 0;
    rec(0,0,0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
