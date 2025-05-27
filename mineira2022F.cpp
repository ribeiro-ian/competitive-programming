/*
    Maratona Mineira 2022F - Caindo de Paraquedas
    https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/F
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll g; cin >> g;
    string str; cin >> str;

    ll sum = 0, e = 0, d = 0; 
    for (auto &c : str) {
        if (c == 'D') {
            sum += g;
        }
        else sum -= g;

        e = min(e, sum);
        d = max(d, sum);

        if (d + abs(e) >= 360 || sum >= 360) {
            cout << "S\n";
            return 0;
        }
    }  

    cout << "N\n";

    return 0;
}