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

    priority_queue <pair <int, pii>> q;
    // first = tamanho do intervalo
    // second = meio do invervalo;

    if (n >= 2) {
        ans[n] = 2;
        q.push({tamanho(1,n), {-1, -n}});
    }

    int j = 0;
    for (int num = 3; num <= n; ++num, ++j) {
        int tam = q.top().first,
            l = -q.top().second.first,
            r = -q.top().second.second;
        int m = meio(l,r);
            
        ans[m] = num;
        if (num == n) continue;

        if (tam % 2 == 0) l++;
        
        // cerr << "tam = " << tam << "; meio = " << m << "; l = " << l << "; r = " << r << "\n";
        // for (int i = 1; i <= n; ++i) {if (ans[i]) cerr << ans[i] << ' '; else cerr << "- ";} cerr << '\n';
        
        if (!ans[meio(l,m)])
            q.push( make_pair( tamanho(l,m), make_pair(-l,-m) ));
        if (!ans[meio(m,r)])
            q.push( make_pair( tamanho(m,r), make_pair(-m,-r) ));
        q.pop();
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}