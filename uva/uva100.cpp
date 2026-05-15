/*
    UVA 100 - The 3n + 1 problem
    https://vjudge.net/problem/UVA-100
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<int, int> memo;
int f(int n){
    if(n == 1) return 1;
    if(memo.count(n)) return memo[n];
    
    int result;
    if(n % 2 == 0)
        result = 1 + f(n / 2);
    else
        result = 1 + f(3*n + 1);
    
    return memo[n] = result;
}

void solve(int i, int j){
    int l = min(i, j),
        r = max(i, j);
    int maxLen = 0;

    for(int k = l; k <= r; k++)
        maxLen = max(maxLen, f(k));

    cout << i << " " << j << " " << maxLen << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int i, j;
    while(cin >> i >> j)
        solve(i, j);

    return 0;
}