#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q, x, y;
    cin >> n >> q;

    vector <ll> v (n), pref(n+1); 
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + v[i-1];
    
    for (int i = 0; i < q; i++){
        cin >> x >> y;

        cout << pref[y] - pref[x-1] << endl;
    }
    
    return 0;
}
