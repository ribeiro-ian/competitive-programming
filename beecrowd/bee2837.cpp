
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ll n, l, h;

    cin >> n >> l >> h;

    vector<ll> num(n+1);
    for(ll i = 1; i < n+1; i++){
        cin >> num[i];
        num[i] += num[i-1];
    }

    vector<ll> mark(n+1, 0);
    for(ll i = 1; i < n+1; i++){
        cin >> mark[i];
        mark[i] += mark[i-1];
    }

    ll e, d;
    ll ans = LONG_MIN, sum = 0;
    for(e = 1, d = 1; e+l <= n; e++){
        while(d <= n && mark[d] - mark[e-1] <= h){
            sum = num[d] - num[e-1];
            if(mark[d] - mark[e-1] >= l){
                ans = max(ans, sum);
                cerr << e << " " << d << endl;
            }
            d++;
        }
        sum = num[min(n,d)] - num[e-1];
        if(mark[min(n,d)] - mark[e-1] >= l){
            ans = max(ans, sum);
            cerr << e << " " << d << endl;
        }
    }

    cerr << e << " " << d << endl;
    
    
    cout << ans << endl;
    
}