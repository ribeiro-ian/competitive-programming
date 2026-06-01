/**
 * Contest : CSES Problem Set
 * Problem : 1662 - Subarray Divisibility
 * Link    : https://cses.fi/problemset/task/1662
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> v(n);
  for (auto &i : v) cin >> i;

  // modular operation thar works properly for any signed value
  auto mod = [&](ll v) {
    return (v % n + n) % n;
  };

  map<ll,ll> freq;
  freq[0] = 1;

  ll sum = 0, cnt = 0;
  for(auto& i : v) {
    sum += mod(i);
    auto rest = mod(sum);
    cnt += freq[rest];
    freq[rest] += 1;
  }

  cout << cnt << '\n';

	return 0;
}
