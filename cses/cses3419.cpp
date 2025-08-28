/*
    CSES 3149 - Mex Grid Construction
    https://cses.fi/problemset/task/3419
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int grid[n][n]; 
    set <int> row[n], col[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            set <int> aux = row[i];
            for (auto x : col[j]) aux.insert(x);

            int idx = 0;
            for (auto x : aux) {
                if (x != idx) 
                    break;
                idx++;
            }
            
            row[i].insert(idx);
            col[j].insert(idx);
            grid[i][j] = idx;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}