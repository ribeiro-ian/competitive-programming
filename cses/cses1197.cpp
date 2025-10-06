/*
    CSES 1197 - Cycle Finding
    https://cses.fi/problemset/task/1197
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <vector<int>> edges;
vector <
bool bellmanFord(int no, int n) {
	vector<int> dist(n, 1e9);
	dist[no] = 0;
  
	for (int i = 0; i < n; i++) {
		for (auto &edge : edges) {
			int u = edge[0],
			    v = edge[1],
                w = edge[2];

			if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                if (i == n-1) {

                    return false;
                }
                dist[v] = dist[u] + w;
            }
		}
	}

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    if (!bellmanFord(1, n)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}