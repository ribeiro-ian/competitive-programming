/*
    CSES 3222 - Sliding Window Distinct Values
    https://cses.fi/problemset/task/3222
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (auto& i : v) 
        cin >> i;

    map<ll, ll> freq;
    for (int i = 0; i < k; ++i) 
        freq[v[i]]++;
    
    cout << freq.size() << ' ';
    for (int i = k; i < n; ++i) {
        freq[v[i]]++;

        if (freq[v[i-k]] == 1) freq.erase(v[i-k]);
        else freq[v[i-k]]--;
        
        cout << freq.size() << ' ';
    }
    cout << '\n';

    return 0;
}