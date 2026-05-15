/*
    Codeforces 1031A - Three Strings
    https://codeforces.com/problemset/problem/1301/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string a, b, c;
    cin >> a >> b >> c;

    for(int i = 0; i < c.size(); ++i){
        if(!(c[i] == a[i] || c[i] == b[i])){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}