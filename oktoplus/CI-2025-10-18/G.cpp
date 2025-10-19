/*
    Codeforces Gym 101845C - Cryptography
    https://codeforces.com/gym/101845/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int n = 127+1;
const ll INF = 1e18;
vector <pair<ll,ll>> graph[n];
vector <vector<ll>> memo(n, vector<ll> (n, INF));

ll sp(ll st, ll end) {
    vector <ll> dist(n+1, INF);
    priority_queue<pair<ll,ll>> q;

    dist[st] = 0;
    q.push({0,st});
    
    while (!q.empty()) {
        auto u = q.top().second;
        q.pop();

        for (auto &[v,w] : graph[u]) {
            ll d = dist[u] + w;
            if (d < dist[v]) {
                dist[v] = d;
                memo[st][v] = d;
                q.push({-d, v});
            }
        }
    }

    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    // change a -> a = cost 0
    for (int i = 0; i < n; ++i) 
        memo[i][i] = 0;

    string s, t;
    cin >> s >> t;
    
    int m;
    cin >> m;

    while (m--) {
        char a, b; ll c;
        cin >> a >> b >> c;

        graph[(ll)a].push_back({(ll)b, c});
    }
    
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ll u = (ll) s[i],
           v = (ll) t[i];

        if (memo[u][v] != INF)
            ans += memo[u][v];
        else {
            ll d = sp(u, v);

            if (d == INF) {
                ans = -1;
                break;
            }
            else
                ans += d;
        }
    }
    cout << ans << '\n';

    return 0;
}