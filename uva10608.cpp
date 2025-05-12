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
    y = find(y), x = find(x);
    if (x==y) return;

    if (len[y] > len[x]) {
        len[y] += len[x];
        parent[x] = y;
    }
    else if (len[y] < len[x]) {
        len[x] += len[y];
        parent[y] = x;
    }
    else {
        parent[x] = y;
        len[y]++;
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

        int ans = 0;
        for (int i = 1; i <= n; i++)  {
            ans = max(ans, len[i]);
            cerr << len[i] << ' ';
        } cerr << "\n";
        
        cout << ans << "\n";
    }

    return 0;
}