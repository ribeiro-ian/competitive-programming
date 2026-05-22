/*
 * Contest : CSES Problem Set
 * Problem : 2107 - String Functions
 * Link    : https://cses.fi/problemset/task/2107
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

    if (i + z[i] > r)
      l = i,
      r = i + z[i];
  }
  return z;
}

vector<int> pi(const string &s) {
  vector<int> p(s.size());
  for (int i = 1, j = 0; i < s.size(); ++i) {
    while (j > 0 && s[j] != s[i]) j = p[j - 1];
    if (s[j] == s[i]) j++;
    p[i] = j;
  }
  return p;
}

int main() {
  fastio

  string s; cin >> s;
  auto z = z_function(s);
  for (auto &i : z) cout << i << ' ';
  cout << '\n';
  auto p = pi(s);
  for (auto &i : p) cout << i << ' ';
  cout << '\n';

  return 0;
}