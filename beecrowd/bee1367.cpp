/*
    Beecrowd 1367 - Ajude!
    https://judge.beecrowd.com/pt/problems/view/1367
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int n) {
    vector<ll> wa('Z'-'A'+1);

    char c;
    string s;
    ll cnt = 0, sum = 0, x;
    while (n--) {
        cin >> c >> x >> s;

        if (s == "incorrect") 
            wa[c-'A']++;
        else {
            cnt++;
            sum += x + 20*wa[c-'A'];
        }
    }
    cout << cnt << ' ' << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while (cin >> n, n)
        solve(n);

    return 0;
}