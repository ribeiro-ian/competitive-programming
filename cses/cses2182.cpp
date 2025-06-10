/*
    CSES 2182 - Divisor Analysis
    https://cses.fi/problemset/task/2182
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9+7;

ll fast_pow(ll x, ll n) {
    ll res = 1;

    while (n > 0) {
        if (n % 2 == 1) res = res * x % MOD;

        x = x * x % MOD;
        n /= 2;
    }
    
    return res;
}

void divisors(ll num, ll &sum, ll &product, ll &cnt) {
    cnt = sum = 0;
    product = 1;

    for (ll n = 1; n * n <= num; ++n) {
        if (num % n == 0) {
            sum = ((sum % MOD) + (n % MOD)) % MOD;
            product = ((product % MOD) * (n % MOD)) % MOD;
            cnt++;

            cerr << "div: " << n;
            
            if (((n % MOD) * (n % MOD)) % MOD != num % MOD) {
                sum = ((sum % MOD) + (num/n % MOD)) % MOD;
                product = ((product % MOD) * (num/n % MOD)) % MOD;
                
                cnt++;
                cerr << " " << num/n;
            }
            cerr << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x, n, k; cin >> n;
    ll num = 1;

    while (n--) {
        cin >> x >> k;

        num = ((num % MOD) * (fast_pow(x, k) % MOD)) % MOD;
    }

    ll sum, product, cnt;
    cerr << "NUM: " << num << "\n"; 
    divisors(num, sum, product, cnt);

    printf("%lli %lli %lli\n", cnt, sum, product);


    return 0;
}