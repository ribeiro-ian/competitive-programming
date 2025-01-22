#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;

void solve(){
    vector <int> a(n), b(n);

    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    printf("%s\n", ((a==b) ? "YES" : "NO"));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1){
        cin >> n;
        if (n==0) break;

        solve();
    }
    

    return 0;
}
