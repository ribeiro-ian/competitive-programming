#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 5;
vector <double> ans(N,0);

int f(string certo, string s) {
    int sz = (int) certo.size();
    int n = (int) s.size();

    int k = abs(sz-n);
    int erros = 0;

    for (int i = 0, j = 0; i < sz && j < n;) {
        if (certo[i] == s[j]) {
            i++, j++;
            continue;
        }
        if (erros >= k) {
            erros++, i++, j++;
            continue;
        }

        if (sz > n) {
            j++;
        }
        else if (sz < n) {
            i++;
        }
    }
}

void solve() {
    string certo;
    vector <string> v(N);
    vector <int> erros(N);
    cin >> certo;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        erros[i] += f(certo, v[i]);
    }


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll tc; cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}