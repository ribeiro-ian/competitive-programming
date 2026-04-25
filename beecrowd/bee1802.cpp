/*
    Bee 1802 - Catálogo de Livros
    https://judge.beecrowd.com/pt/problems/view/1802
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    auto read = [](vector<ll>& v) {
        int n; cin >> n;
        v.resize(n);
        for (auto& i : v) cin >> i;
    };
    
    vector<ll> p, m, f, q, b;
    read(p); read(m); read(f); read(q); read(b);

    int k; cin >> k;

    vector<ll> all;
     for (auto& pi : p)
        for (auto& mi : m)
            for (auto& fi : f)
                for (auto& qi : q)
                    for (auto& bi : b)
                        all.push_back(pi + mi + fi + qi + bi);
    sort(all.rbegin(), all.rend());

    ll sum = 0;
    for (int i = 0; i < k; ++i)
        sum += all[i];

    cout << sum << '\n';

    return 0;
}