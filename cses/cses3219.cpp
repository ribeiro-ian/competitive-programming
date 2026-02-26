/*
    CSES 3219 - Sliding Window Mex
    https://cses.fi/problemset/task/3219
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5+5;
vector<ll> cnt(N);
priority_queue<ll, vector<ll>, greater<ll>> q;

ll ans() {
    while (!q.empty() && cnt[q.top()] > 0) 
        q.pop();

    return q.top();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < N; ++i) 
        q.push(i);
    int n, k;
    cin >> n >> k;

    vector<ll> v(n);    
    for (auto& i : v) 
        cin >> i;

    for (int i = 0; i < k; ++i) 
        if (v[i] < N) cnt[v[i]]++;
    cout << ans() << ' ';
    
    for (int i = k; i < n; ++i) {
        if (v[i-k] < N) {
            cnt[v[i-k]]--;
            
            if (!cnt[v[i-k]])
                q.push(v[i-k]);
        }
        if (v[i] < N) cnt[v[i]]++;
        cout << ans() << ' ';
    }
    cout << '\n';

    return 0;
}