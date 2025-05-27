/*
    Beecrowd 1301 - Produto do Intervalo
    https://judge.beecrowd.com/pt/problems/view/1301
*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;
vector <ll> bit, vet;
ll n, k;

void upd(ll i, ll v) {
    for (; i <= n; i += (i&-i))
        bit[i] += v;
}

pair<ll,ll> product(ll i) {
    ll ans = 1, cnt = 0;

    for (; i > 0; i -= (i&-i)) {
        if (!bit[i]) cnt++;
    }
    return {ans, cnt};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> k) {
        vet.assign(n+1,0);
        bit.assign(n+1,1);

        for (int i = 1; i <= n; ++i) {
            cin >> vet[i];
            upd(i, vet[i]);
        }
        cerr << "\nbit: \n";
        for (int i = 1; i <= n; ++i) {
            cerr << bit[i] << " ";
        } cerr << "\n\n";

        string ans = "";
        while (k--) {
            char op;
            ll a, b;
            cin >> op >> a >> b;

            if (op == 'C') {
                upd(a, b-vet[a]);
                vet[a] = b;

                cerr << "\nbit: \n";
                for (int i = 1; i <= n; ++i) {
                    cerr << bit[i] << " ";
                } cerr << "\n\n";
            }
            else {
                pair <ll, ll> retB = product(b),
                    retA = product(a-1);

                ll qntdZero = retB.S - retA.S;
                cerr << "0 em B: " << retB.S << "; 0 em A: " << retA.S << endl;
                ll ret = retB.F / retA.F;

                cerr << "ret = " << ret << "\n";

                if (qntdZero) ans += "0";
                else {
                    ans += (ret > 0 ? "+" : "-");
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}