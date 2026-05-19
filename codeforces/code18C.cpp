/*
 * Contest : Codeforces
 * Problem : 18C - Stripe
 * Link    : https://codeforces.com/problemset/problem/18/C
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<ll> v(n);
  ll total = 0, sum = 0, cnt = 0;
  for (auto &i : v) {
    cin >> i;
    total += i;
  }

  for (int i = 0; i < n - 1; ++i) {
    sum += v[i];
    cnt += sum == total - sum;
  }
  cout << cnt << '\n';

  return 0;
}