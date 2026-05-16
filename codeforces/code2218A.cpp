/*
  Codeforces 2218A - The 67th Integer Problem
  https://codeforces.com/contest/2218/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int x; cin >> x;
  if (x < 0) cout << x;
  else
    cout << min(x + 1, 67);
  cout << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}