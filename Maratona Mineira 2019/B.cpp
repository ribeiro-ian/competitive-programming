/*
    Maratona Mineira 2019 - B - Podando Galhos
    https://codeforces.com/group/YgJmumGtHD/contest/102223/problem/B
*/



#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+1; 
vector<int> filhos[N],
            pai(N), ans(N);

void dfs(int u, int t) {
    if (ans[u]) return;
    ans[u] = t;
    for (auto& v : filhos[u])
        dfs(v, t);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pai[i];

        if (pai[i]!=-1)
            filhos[pai[i]].push_back(i);
    }

    int q = n, tempo = 1;
    while (q--) {
        int no; cin >> no;
        dfs(no, tempo);
        tempo++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i==n];
    }

    return 0;
}