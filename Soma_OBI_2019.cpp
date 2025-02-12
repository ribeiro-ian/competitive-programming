#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;

    vector <ll> v(n), pref(n+1);
    map<ll, ll> prefSums;

    for (int i = 0;     i < n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + v[i-1];

    for (int i = 1; i <= n; i++)
        printf("%i ", pref[i]);
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        ans++; 
    }

    cout << ans << endl;

    return 0;
}
