/*
    CSES 1194 - Monsters
    https://cses.fi/problemset/task/1194
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const int MAXN = 1000+1;
pii pos[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
char posChar[] = {'U', 'D', 'L', 'R'};
char grid[MAXN][MAXN];
int you[MAXN][MAXN], monster[MAXN][MAXN], n, m;

map <pii, bool> exits;
queue <pii> q;

pii bfs(int i, int j) {
    queue <pii> q;
    q.push({i, j});
    you[i][j] = 0;

    while (!q.empty()) {
        tie(i,j) = q.front();
        q.pop();

        if (exits.count({i,j})) return {i,j};
        int v = you[i][j];
        for (auto &[x,y] : pos) {
            int lin = x + i,
                col = y + j;
            
            if (lin >= 0 && lin < n && col >= 0 && col < m && grid[lin][col] != '#' && you[lin][col] == -1 && v+1 < monster[lin][col]) {
                q.push({lin,col});
                you[lin][col] = v+1;
            }
        }
    }

    return {-1,-1};
}

void bfsMonster() {
    while (!q.empty()) {
        int i, j;
        tie(i,j) = q.front();
        q.pop();
        
        int v = monster[i][j];
        for (auto &[x,y] : pos) {
            int lin = x + i,
                col = y + j;
            
            if (lin >= 0 && lin < n && col >= 0 && col < m && grid[lin][col] != '#' && v+1 < monster[lin][col]) {
                q.push({lin,col});
                monster[lin][col] = v+1;
            }
        }
    }
}

char step(int &i, int &j) {
    int v = you[i][j];

    for (int k = 0; k < 4; ++k) { 
        int x = pos[k].first,
            y = pos[k].second;
        int lin = x + i,
            col = y + j;

        if (lin >= 0 && lin < n && col >= 0 && col < m && you[lin][col] == v-1) {
            i = lin;
            j = col;
            return posChar[k];
        }
    }
    return '-';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    pii start;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            grid[i][j] = (c == '#' ? '#' : '.');

            you[i][j] = -1;
            monster[i][j] = 1e9;

            if (c == 'A') start = {i,j};
            else if (c=='M') {
                q.push({i,j});
                monster[i][j] = 0;
            }
            
            if (c != '#' && (i == 0 || i == n-1) && (j != 0 && j != n-1)) {
                exits[{i,j}] = true;
            }
            if (c != '#' && (j == 0 || j == m-1) && (i != 0 && i != n-1)) {
                exits[{i,j}] = true;
            }
            if (c != '#' && (n <=2 || m <= 2))
                exits[{i,j}] = true;
        }
    }

    bfsMonster();
    pii end = bfs(start.first, start.second);

    vector <char> ans;
    if (end.first == -1) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    if (end != start) {
        while (you[end.first][end.second] != 0) {
            int i, j;
            tie(i, j) = end;
            ans.push_back( step(i,j) );
            end = {i,j};
        }
    }

    cout << (int)ans.size() << '\n';
    for (int i = ans.size()-1; i >= 0; --i) 
        cout << ans[i];
    if (ans.size()) cout << '\n';

    return 0;
}