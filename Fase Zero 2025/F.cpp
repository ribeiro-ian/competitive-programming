#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<ll> vec;
ll n;

void solve(ll x) {
  ll cnt = 0;
  for (int i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
      int l = j + 1, r = n - 1;

      while (l < r) {
        int sum = vec[j] + vec[i] + vec[l] + vec[r];

        if (sum == x) 
          cnt++;
        
        else if (sum > x) 
          r--;
        
        else 
          l++;
      }
    }
  }

  cout << cnt << "\n";
}

int main() {
  fastio

  ll x, q; cin >> n;
  vec.resize(n);
  for (int i = 0; i < n; ++i) cin >> vec[i];

  sort(vec.begin(), vec.end()); cin >> q;

  while (q--) {
    cin >> x;
    solve(x);
  }

  return 0;
}