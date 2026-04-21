/*
    Codeforces 20C - Dijkstra?
    https://codeforces.com/problemset/problem/20/C
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> graph[n+1];
    vector<ll> dist(n+1, 1e18);
    vector<ll> child(n+1, -1);

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    priority_queue<pair<ll,ll>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();

        for (auto &[v,w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                child[v] = u;
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    if (dist[n] == 1e18) {
        cout << "-1\n";
    }
    else {
        vector <ll> path;
        for (auto i = n;; i = child[i]) {
            if (i==-1) break;
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for (auto &i : path)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}