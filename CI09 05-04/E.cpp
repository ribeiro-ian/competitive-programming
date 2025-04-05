/*
    UVA 10608 - Friends
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector <int> parent, len;

int find(int x) {
    if (parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

void join(int x, int y){
    y = find(parent[y]), x = find(parent[x]);

    parent[y] = find(parent[x]);

    if (len[y] >= len[x]) {
        len[y] += len[x];
    }
    else {
        len[x] += len[y];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc, n, m, a, b;

    cin >> tc;
    while (tc--) {
        cin >> n >> m;

        parent.resize(n+1);
        len.assign(n+1, 1);
        
        for (int i = 1; i <= n; i++) 
            parent[i] = i;
        
        while (m--) {
            cin >> a >> b;

            join(a, b);
        }

        for (int i = 1; i <= n; i++) 
            parent[i] = find(parent[i]);
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = count(parent.begin()+1, parent.end(), i);
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }

    return 0;
}