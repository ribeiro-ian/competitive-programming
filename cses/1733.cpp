/**
 * Contest : CSES Problem Set
 * Problem : 1733 - Finding Periods
 * Link    : https://cses.fi/problemset/task/1733
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
  fastio

  string s; cin >> s;
  auto z = z_function(s);
  for (auto &c : s) cerr << c << ' ';
  cerr << '\n';
  for (auto &i : z) cerr << i << ' ';
  cerr << '\n';

  for (int i = z.size() - 1; i >= 0; --i)
    if (i + z[i] == s.size()) cout << z[i] << ' ';
  cout << '\n';

  return 0;
}