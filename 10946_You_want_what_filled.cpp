#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
int n, m, hole_cnt;
char grid[MAX][MAX];
vector <pair <char, int>> hole;

void bfs(int lin, int col){
    if (lin < 1 || col < 1 || lin > n || col > m)
        return;

    if (grid[lin][col] != hole[hole_cnt].first)
        return;

    grid[lin][col] = '.';
    hole[hole_cnt].second++;

    bfs(lin+1, col);
    bfs(lin-1, col);
    bfs(lin, col+1);
    bfs(lin, col-1);
}

bool cmp(pair <char, int> a, pair <char, int> b){
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){
    int problem = 1;

    while(1){
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> grid[i][j];
            }
        }


        hole.clear();
        hole_cnt = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (grid[i][j] != '.'){
                    hole.push_back(make_pair(grid[i][j], 0));
                    bfs(i, j);
                    hole_cnt++;
                }
            }
        }

        sort(hole.begin(), hole.end(), cmp);

        printf("Problem %i:\n", problem++);
        for (auto &p : hole)
            printf("%c %i\n",p.first,p.second);
    }

    return 0;
}
