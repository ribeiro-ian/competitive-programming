/*
    Beecrowd 1274 - P-Networks
    https:*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
void solve(){
    vector<int> to(n+1), pos(n+1), cur(n+1), cnt(n+1);
    bool flag = false;

    for(int i = 1; i <= n; ++i){
        cin >> to[i];
        cnt[to[i]]++;
        if(cnt[to[i]] > 1) flag = true;
    }

    if(flag){
        cout << "No solution\n";
        return;
    }

    for(int i = 1; i <= n; ++i) 
        cur[i] = i, pos[i] = i;
    
    vector<int> from(n+1);
    for(int i = 1; i <= n; ++i) from[to[i]] = i;

    vector<int> cursos;
    for(int k = 1; k <= n; ++k){
        int p = pos[from[k]];
        while(p > k){
            int f1 = cur[p-1], f2 = cur[p];
            cur[p-1] = f2; cur[p] = f1;
            pos[f1] = p; pos[f2] = p-1;

            cursos.push_back(p-1);
            p--;
        }
    }

    cout << cursos.size();
    for(auto& s : cursos) cout << ' ' << s;
    cout << '\n';
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n, n)
        solve();

    return 0;
}