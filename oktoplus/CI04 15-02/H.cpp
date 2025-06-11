/*
    Bee 1579 - Transporte de Painéis Solares
    https://judge.beecrowd.com/pt/problems/view/1579
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tc, n, c, f, total;
vector <ll> p(101), cam(11);

ll func(ll m){
    ll cnt = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += p[i];
        
        if (sum > m){
            sum = p[i];
            cnt++;
        }
    }

    return cnt;
}

ll bs(){
    ll l = *max_element(p.begin(), p.end()),
        r = total;
    ll ans = 0;

    while (l <= r){
        ll m = (l+r)/2;

        if (func(m) <= c){
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int main(){
    scanf("%lli", &tc);
    
    while (tc--)
    {
        scanf("%lli %lli %lli", &n, &c, &f);

        total = 0;
        for (int i = 0; i < n; i++){
            scanf("%lli", &p[i]);
            total += p[i];
        }

        ll ans = bs();
        printf("%lli $%lli\n", ans, ans*f*c);
    }
    
    return 0;
}