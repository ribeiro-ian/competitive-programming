/*
    UVA 657 - You want what filled?
    https://vjudge.net/problem/UVA-10946
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string grid[51];
int n, m, caseNum = 0;

void dfs(int i, int j, char c, int& cnt){
    grid[i][j] = '.';
    cnt++;
    for(auto [dx, dy] : {pair{1,0},{-1,0},{0,1},{0,-1}}){
        int x = i+dx, y = j+dy;
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == c)
            dfs(x, y, c, cnt);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n >> m, n && m){
        for(int i = 0; i < n; ++i) cin >> grid[i];

        vector<pair<char,int>> arr;
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) 
                if(grid[i][j] != '.'){
                    auto& [ch, cnt] = arr.emplace_back(grid[i][j], 0);
                    dfs(i,j, ch, cnt);
                }
            
        sort(arr.begin(), arr.end(), [](auto& a, auto& b){
            return a.second != b.second ? a.second > b.second : a.first < b.first;
        });

        cout << "Problem " << ++caseNum << ":\n";
        for(auto& [ch, len] : arr)
            cout << ch << ' ' << len  << '\n';        
    }

    return 0;
}