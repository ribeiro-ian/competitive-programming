/*
 * Contest : Beecrowd
 * Problem : 1238 - Combinador
 * Link    : https://judge.beecrowd.com/pt/problems/view/1238
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  string a, b;
  cin >> a >> b;

  int i = 0, j = 0;
  string ans;
  while (i < a.size() && j < b.size()) {
    ans += a[i++];
    ans += b[j++];
  }
  while (i < a.size()) ans += a[i++];
  while (j < b.size()) ans += b[j++];

  cout << ans << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}