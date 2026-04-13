/*
    Codeforces 1206A - Choose Two Numbers
    https://codeforces.com/problemset/problem/1206/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, x;
    set<int> a, b;
    
    cin >> n;
    while (n--) { 
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    while (m--) {
        cin >> x;
        b.insert(x);
    }

    cout << *a.rbegin() << ' ' << *b.rbegin() << '\n';

    return 0;
}