/*
 * Contest : CSES
 * Problem : 1073 - Towers
 * Link    : https://cses.fi/problemset/task/1073
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
  vector<ll> vs = v;
  sort(vs.begin(), vs.end());
  reverse(vs.begin(), vs.end());

  for (auto &i : v) cerr << i << ' ';
  cerr << '\n';
  for (auto &i : vs) cerr << i << ' ';
  cerr << '\n';

  return 0;
}