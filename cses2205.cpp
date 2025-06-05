/*
    CSES 2205 - Gray Code
    https://cses.fi/problemset/task/2205
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(int i, int v) {
    if (i == 0) {
        cout << '\n';
        return;
    }
        

    cout << v;
    solve(i-1, 0);
    cout << v;
    solve(i-1, 1);
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    // cout << "0\n1\n";

    solve(n, 1);

    return 0;
}