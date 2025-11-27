/*
    Codeforces 2155B - Abraham's Great Escape
    https://codeforces.com/problemset/problem/2155/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector<bool>> escape;
int n, k;
unordered_map <char, pair<int,int>> dir = {
    {'U', {-1,0}},
    {'D', {1, 0}},
    {'R', {0, 1}},
    {'L', {0,-1}},
};

bool validPos(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n) return true;
    return false;
}

void solve() {
    cin >> n >> k;

    if (n*n-1 == k) {
        cout << "NO\n";
        return;
    }
    else if (n*n == k) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "U";
            }
            cout << '\n';
        }
        return;
    }
    
    cout << "YES\n";

    escape.assign(n, vector<bool>(n,false));
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto &[c, d] : dir) {
                int x = i + d.first,
                    y = j + d.second;
                
                if (cnt < k) {
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        cout << c;
                        escape[i][j] = true;
                        cnt++;
                    }
                    else if (validPos(x,y) && escape[x][y]) {
                        cout << c;
                        escape[i][j] = true;
                        cnt++;
                    }
                    break;
                }
                else {
                    if (validPos(x,y) && !escape[x][y]) {
                        cout << c;
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}