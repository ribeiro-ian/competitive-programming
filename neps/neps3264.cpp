/*
    OBI 2025 - Fase 2 - Feirinha de Artesanato
    https://neps.academy/br/exercise/3264
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(multiset<ll>& t, ll& ans) {
    if (!t.empty()) {
        ans += *t.begin();
        t.erase(t.begin());
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x;
    cin >> n;
    vector<int> tipo(n);
    for (auto& i : tipo) 
        cin >> i;
    
    multiset<ll> t1, t2;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (tipo[i] == 1)
            t1.insert(x);
        else
            t2.insert(x);
    }

    int c; cin >> c;
    ll ans = 0;
    while (c--) {
        cin >> x;

        if (x == 0) {
            ll p1 = t1.empty() ? LLONG_MAX : *t1.begin();
            ll p2 = t2.empty() ? LLONG_MAX : *t2.begin();
            
            if (p1 <= p2) 
                add(t1, ans);
            else 
                add(t2, ans);
        }
        else if (x==1) 
            add(t1, ans);
        else if (x==2) 
            add(t2, ans);
    }
    cout << ans << '\n';
        
    return 0;
}