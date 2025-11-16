/*
    CSES 1687 - Company Queries I
    https://cses.fi/problemset/task/1687
*/

#include <bits/stdc++.h>
using namespace std;

const int K = 31, N = 2e5+1;
int succ[N+1][K];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n, q;
    cin >> n >> q; 
 
    for (int k = 0; k < K; k++) succ[1][k] = -1;
    for (int i = 2; i <= n;++ i) {
        cin >> succ[i][0];
    }
 
    // pre process
    for (int k = 1; k < K; ++k) {
        for (int i = 2; i <= n; ++i) {
            int mid = succ[i][k-1];
            succ[i][k] = (mid == -1 ? -1 : succ[mid][k-1]);
        }
    }
 
    while (q--) {
        int x, k;
        cin >> x >> k;
 
        for (int i = 0; i < K; ++i) {
            if (k & (1<<i)) {
                x = succ[x][i];
                if (x == -1) break;
            }
        }
        cout << x << '\n';
    }
 
    return 0;
}