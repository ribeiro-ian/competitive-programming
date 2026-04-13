/*
    Beecrowd 1024 - Criptografia
    https://judge.beecrowd.com/pt/problems/view/1024
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    getline(cin, s);

    for (auto&c : s) 
        if (isalpha(c))
            c += 3;
    reverse(s.begin(), s.end());

    for (int i = s.size()/2; i < s.size(); ++i)
        s[i]--;
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    cin.ignore();
    while (tc--) solve();

    return 0;
}