/**
 * Contest : CSES Problem Set
 * Problem : 1084 - Apartments
 * Link    : https://cses.fi/problemset/task/1084
 */

#include <bits/stdc++.h>
#include <ios>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> desired(n), ap(m);
  for (auto &i : desired) cin >> i;
  for (auto &i : ap) cin >> i;

  sort(desired.begin(), desired.end());
  sort(ap.begin(), ap.end());

  ll i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    if (ap[j] < desired[i] - k) j++;
    else if (ap[j] > desired[i] + k) i++;
    else {
      i++, j++, ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}