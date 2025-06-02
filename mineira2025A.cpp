/*
    Maratona Mineira 2025A - Antissocial
    https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

vector <int> ans;

int meio(int l, int r) { return l+(r-l)/2; }
int tamanho(int l, int r) { 
    int tam = r-l+1;
    if (tam % 2 == 0) tam--;
    return tam;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    ans.assign(n+1, 0);
    ans[1] = 1;

    priority_queue <pii> q;
    // first = tamanho do intervlao
    // second = meio do invervalo;

    if (n >= 2) {
        ans[n] = 2;
        q.push({tamanho(1,n), meio(1,n)});
    }

    for (int num = 3; num <= n; ++num) {
        int tam = q.top().first,
            m = q.top().second;
        
        ans[m] = num;
        if (num == n) continue;

        int l = m - tam/2,
            r = m + tam/2;
        if (tam % 2 == 0) l++;
        
        if (!ans[meio(l,m)])
            q.push(make_pair( tamanho(l,m), meio(l,m) ));
        if (!ans[meio(m,r)])
            q.push(make_pair( tamanho(m,r), meio(m,r) ));
        
        q.pop();
        for (int i = 1; i <= n; ++i) {
            cerr << ans[i] << ' ';
        }
        cerr << '\n';
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}