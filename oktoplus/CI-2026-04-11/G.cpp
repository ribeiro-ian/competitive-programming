#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, p;
const int MAX = 501;
vector<vector<ll>> b(MAX, vector<ll>(MAX, 0)),
                   w(MAX, vector<ll>(MAX, 0));

void pref(vector<vector<ll>>& grid) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            grid[i][j] += grid[i][j-1] + grid[i-1][j];
        }
    }
}

// 1 -> Preta, 2-> Branca
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> p;
    int lin, col;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout <<b[i][j] << ' ';
        }
        cout << endl;
    }

    // Preta -> 1
    for (int i = 0; i < p; ++i) {
        cin >> lin >> col;
        b[lin][col] = 1;
    }
    // Branca -> 2
    for (int i = 0; i < p; ++i) {
        cin >> lin >> col;
        w[lin][col] = 1;
    }
    pref(b), pref(w);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout <<b[i][j] << ' ';
        }
        cout << endl;
    }



    return 0;
}