#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll findString(string &str, string sub, ll pos, ll n) {
    ll aux = str.find(sub, pos);
    return (aux == str.npos ? n+1 : aux);
}

void solve() {
    ll n; cin >> n;
    string str; cin >> str;
    ll cnt = 0, pos = 0;
    
    while (1) {
        ll next = findString(str, "map", pos, n);
        next = min(findString(str, "pie", pos, n), next);

        if (next == n+1) break;
        cnt++;
        pos = next+3;
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}