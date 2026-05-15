/*
    UVA 10763 - Foreign Exchange
    https://vjudge.net/problem/UVA-10763
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int n){
    multiset<pair<int,int>> freq;

    while(n--){
        int from, to;
        cin >> from >> to;
        auto it = freq.find({to, from});
        
        if(it != freq.end())
            freq.erase(it);
        else
            freq.insert({from, to});
    }

    cout << (freq.empty() ? "YES" : "NO") << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while(cin >> n, n)
        solve(n);

    return 0;
}