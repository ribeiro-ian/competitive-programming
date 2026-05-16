#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

bool solve() {
  ll x, n, m;
  cin >> x >> n >> m;

  while (n && x / 2 + 10 < x - 10) {
    x = x / 2 + 10;
    n--;
  }

  if (x - 10 * m <= 0) return true;

  while (n) {
    x = x / 2 + 10;
    if (x - 10 * m <= 0) return true;
    n--;
  }

  if (x > 0) return false;
  return true;
}

int main() {
  fastio

  int t; cin >> t;

  while (t--) { cout << (solve() ? "YES" : "NO") << '\n'; }

  return 0;
}