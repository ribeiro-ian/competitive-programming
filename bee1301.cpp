/*
    Beecrowd 1301 - Produto do Intervalo
    https://judge.beecrowd.com/pt/problems/view/1301
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
vector <ll> bit, vet;
ll n, k;

void upd(ll i, ll v) {
    for (; i <= n; i += (i&-i))
        bit[i] += v;
}

ll sum(ll i) {
    ll ans = 1;
    for (; i > 0; i -= (i&-i))
        ans *= bit[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> k) {
        vet.assign(n+1,0);
        bit.assign(n+1,0);

        for (int i = 1; i <= n; ++i) {
            cin >> vet[i];
            upd(i, vet[i]);
        }

        string ans = "";
        while (k--) {
            char op;
            ll a, b;
            cin >> op >> a >> b;

            if (op == 'c') {
                upd(a, b-vet[a]);
                vet[a] = b;
            }
            else {
                ll ret = sum(b) - sum(a-1);

                if (ret == 0) ans += "0";
                else {
                    ans += (ret > 0 ? "+" : "-");
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}