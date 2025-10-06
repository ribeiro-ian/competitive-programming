/*
    Beecrowd 1183 - Acima da Diagonal Principal
    https://judge.beecrowd.com/pt/problems/view/1183
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n = 12, t = 0;
    float grid[n][n], s = 0;
    
    char c; cin >> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (i+j > 2*i) {
                s += grid[i][j];
                t++;
            }
        }
    }

    if (c == 'S') printf("%.1f\n", s);
    else printf("%.1f\n", s/t);

    return 0;
}