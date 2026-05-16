/*
  Codeforces 1036A - Function Height
  https://codeforces.com/problemset/problem/1036/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, k;
  cin >> n >> k;

  ll ans = ceil((long double)k / n);
  cout << ans << '\n';
  cerr << k / n << endl;

  return 0;
}