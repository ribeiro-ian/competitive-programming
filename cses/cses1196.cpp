/*
    CSES 1196 - Flight Routes
    https://cses.fi/problemset/task/1196
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector<pair<int,ll>>> graph;

int n, m, k;
vector <ll> ans;
void dijkstra(int src = 1) {
    vector<priority_queue<ll>> costs(n+1);
    priority_queue<pair<ll,int>> pq;
    
    costs[1].push(0);
    pq.push({0,src});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (-dist > costs[u].top()) continue;
        for (auto &[v,w] : graph[u]) {
            ll d = -dist + w;
            if (costs[v].size() < k) {
                costs[v].push(d);
                pq.push({-d, v});
            }
            else if (d < costs[v].top()) {
                costs[v].pop();
                costs[v].push(d);
                pq.push({-d, v});
            }
        }
    }

    while (!costs[n].empty()) {
        ans.push_back(costs[n].top());
        costs[n].pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    graph.resize(n+1);
    while (m--) {
        int a, b; ll c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijkstra();
    for (int i = ans.size()-1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}