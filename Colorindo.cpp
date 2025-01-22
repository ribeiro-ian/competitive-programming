#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int n, m, x, y, k, a, b;
vector <vector <int>> v;
vector <vector <bool>> visited;

void bfs(pii s){
    queue <pii> q;

    visited[s.first][s.second] = true;
    q.push(s);

    int cnt = 1;
    while (!q.empty()) {
        pii u = q.front();
        q.pop();

        int Yaxis[] = {u.first, u.first+1, u.first-1},
            Xaxis[] = {u.second, u.second+1, u.second-1};

        for (auto &i : Yaxis){
            for (auto &j : Xaxis){
                if (!(i >= 1 && i <= n) || !(j >= 1 && j <= m))
                    break;

                if (!visited[i][j]){
                    cnt++;
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                }
            }
        }
    }

    printf("%i\n", cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    v.resize(n+1);
    visited.resize(n+1);

    for (int i = 1; i <= n; i++){
        v[i].resize(m+1, 0);
        visited[i].resize(m+1, false);
    }

    for (int i = 0; i < k; i++){
        cin >> a >> b;

        visited[n-a+1][b] = true;
    }

    bfs(make_pair(n-x+1, y)); // começo

    return 0;
}
