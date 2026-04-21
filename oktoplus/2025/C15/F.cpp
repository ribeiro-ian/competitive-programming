#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 400, INF = 1e9;
int n, r;
vector < pair<int,int> > graph[N];
vector <int> planetas, temp;
vector <bool> valido;
int memo[N][N][N][2];

bool cmp(int a, int b) {
    return planetas[a] < planetas[b];
}

int dijkstra(int a, int b, int k, int t) {
    vector <int> dist(n, INF);
    priority_queue <pair<int,int>> q;

    dist[a] = 0;
    q.push({0, a});

    while (!q.empty()) {
        auto u = q.top().second;
        q.pop();

        for (auto &[v,w] : graph[u]) {
            if (v != b && !valido[v]) continue;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }

    return (dist[b] == INF ? -1 : dist[b]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> r;
    planetas.resize(n); temp.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> planetas[i];

        temp[i] = i;
    }
    sort(temp.begin(), temp.end(), cmp);
    

    while (r--) {
        int x, y, d;
        cin >> x >> y >> d;
        x--, y--;

        graph[x].push_back({y,d});
        graph[y].push_back({x,d});
    }

    int q; cin >> q;
    
    while (q--) {
        valido.assign(n, false);

        int a, b, k, t;
        cin >> a >> b >> k >> t;
        a--, b--;

        // K Hottest
        int cnt = 0, i;
        if (t) {
            i = n-1;
            while (i >= 0 && cnt < k) {
                valido[temp[i]] = true;
                if (i-1 >= 0 && planetas[temp[i]] != planetas[temp[i-1]]) cnt++;
                i--;
            }
        }
        // K coldest
        else {
            i = 0;
            while (i <  n && cnt < k) {
                valido[temp[i]] = true;
                if (i+1 < n && planetas[temp[i]] != planetas[temp[i+1]]) cnt++;
                i++;
            }
        }
        // for (auto &i : planetas) cerr << i << ' '; cerr << '\n';
        // for (auto &i : temp) cerr << i << ' '; cerr << '\n';
        // for (bool i : valido) cerr << i << ' '; cerr << '\n';

        cout << dijkstra(a,b,k,t) << '\n';
    }


    return 0;
}