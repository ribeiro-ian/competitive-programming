/*
    CSES 1144 - Salary Queries
    https://cses.fi/problemset/task/1144
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5+1, MAX = 1e6+6, SZ = 1e3;
const ll ST = 1 << (ll)ceil(log2(MAX));
map<ll,ll> freq;
vector<ll> tree(4*MAX), salary(N), range(MAX);
ll n, q;

inline ll c(ll i) {
    return (i-1) / SZ;
}

void build() {
    while (n & (n-1)) n++;

    for (int i = 0; i < MAX; ++i)  
        tree[i+ST] = range[i];
    
    for (int i = ST-1; i >= 1; --i) 
        tree[i] = tree[2*i] + tree[2*i+1];
}

void update(ll idx, ll x) {
    idx += ST;
    tree[idx] = x;

    for (int i = idx/2; i >= 1; i /= 2) 
        tree[i] = tree[2*i] + tree[2*i+1];
}

ll query(ll l, ll r) {
    ll sum = 0;
    for (l += ST, r += ST+1; l < r; l /= 2, r /= 2) {
        if (l & 1) sum += tree[l++];
        if (r & 1) sum += tree[--r];
    }
    return sum;
}

ll brute(ll l, ll r) {
    auto it = freq.lower_bound(l);
    ll cnt = 0;

    while (it != freq.end() && it->first <= r) {
        cnt += it->second;
        it++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        ll sal; cin >> sal;
        salary[i] = sal;
        freq[sal]++;
        range[c(sal)]++;
    }
    build();

    while (q--) {
        char op; cin >> op;
        
        if (op == '!') {
            ll k, x; 
            cin >> k >> x;

            auto old = salary[k-1];
            salary[k-1] = x;

            range[c(old)]--; 
            range[c(x)]++;

            freq[old]--;
            freq[x]++;

            update(c(old), range[c(old)]);
            update(c(x), range[c(x)]);          
        }
        else {
            ll a, b;
            cin >> a >> b;

            ll cA = c(a),
               cB = c(b),
               ans = 0;

            ans += brute(a, min(b, SZ*(cA+1)));
            ans += query(cA+1, cB-1);

            if (c(b) != cA) 
                ans += brute(max(a,SZ*cB + 1), b);
            
            cout << ans << '\n';
        }
    }

    return 0;
}