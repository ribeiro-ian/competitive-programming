/*
    CSES 1132 - Tree Distances I
    https://cses.fi/problemset/task/1132
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2*1e5+1;
vector<int> graph[N], toLeaf(N);
int ans = 0;

int dfs1(int no, int p) {
    multiset <int> best;

    for (auto &v : graph[no]) {
        
    }
        
    return toLeaf[1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs1(1, -1);
    cout << ans << '\n';


    return 0;
}