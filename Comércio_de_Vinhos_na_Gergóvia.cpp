#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, x;
vector <ll> a;

void solve(int n){
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    ll ans, aux;
    ans = aux = 0;

    for (int i = 0; i < n; i++){
        aux += a[i];
        ans += abs(aux);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1){
        cin >> n;
        if (!n) break;
        
        solve(n);
    }
    

    return 0;
}
