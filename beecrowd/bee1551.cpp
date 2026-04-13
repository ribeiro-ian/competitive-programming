/*
    Beecrowd 1551 - Frase Completa
    https://judge.beecrowd.com/pt/problems/view/1551
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    getline(cin, s);

    set<char> unique;
    for (auto&c : s) {
        if (c >= 'a' && c <= 'z')
            unique.insert(c);
    }

    cerr << unique.size() << '\n';
    if (unique.size() >= 26)
        cout << "frase completa\n";
    else if (unique.size() >= 13)
        cout << "frase quase completa\n";
    else
        cout << "frase mal elaborada\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    cin.ignore();
    while (tc--) solve();

    return 0;
}