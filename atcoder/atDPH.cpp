/*
    AtCoder DP Contest - Grid 1
    https://atcoder.jp/contests/dp/tasks/dp_h
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int h, w;
    cin >> h >> w;

    char grid[h+1][w+1];
    for(int i = 1; i <= h; ++i) 
        for(int i = 1; i <= w; ++i)
            cin >> grid[h][w];
    
    return 0;
}