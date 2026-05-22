/*
 * Contest : CSES Problem Set
 * Problem : 1092 - Two Sets
 * Link    : https://cses.fi/problemset/task/1092/
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;

  if (n * (n + 1) / 2 % 2) {
    cout << "NO\n";
    return 0;
  }

  vector<ll> a, b;
  ll target = n * (n + 1) / 4, sA = 0, sB = 0;

  for (int i = n; i > 0; --i) {
    if (sA + i <= target) {
      sA += i;
      a.push_back(i);
    } else {
      sB += i;
      b.push_back(i);
    }
  }

  cout << "YES\n";
  cout << a.size() << '\n';
  for (auto &i : a) cout << i << ' ';
  cout << '\n';

  cout << b.size() << '\n';
  for (auto &i : b) cout << i << ' ';
  cout << '\n';

  return 0;
}
