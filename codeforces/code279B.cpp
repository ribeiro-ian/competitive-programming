/*
 * Contest : Codeforces
 * Problem : 279B - Books
 * Link    : https://codeforces.com/problemset/problem/279/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, t;
  scanf("%lli %lli", &n, &t);

  ll a[n];
  for (int i = 0; i < n; i++) scanf("%lli", &a[i]);

  int ans = 0;
  ll sum = 0;
  for (int i = 0, r = 0; i < n; i++) {
    while (r < n && sum + a[r] <= t) {
      sum += a[r];
      r++;
    }

    ans = max(ans, r - i);
    sum -= a[i];
  }

  cout << ans << '\n';

  return 0;
}