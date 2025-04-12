/*
    Codeforces 489B - BerSU Ball
    https://codeforces.com/problemset/problem/489/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;

    cin >> n;
    int b[n];
    for (auto &e : b)
        cin >> e;
        
    cin >> m;
    int g[m];
    for (auto &e : g)
        cin >> e;
        
    sort(b, b+n);
    sort(g, g+m);
    
    int cnt = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(b[i] - g[j]) <= 1) {
            cnt++;
            i++;
            j++;
        }
        else if (b[i] < g[j])
            i++;
        else
            j++;
    }

    cout << cnt << "\n\n";

    return 0;
}
