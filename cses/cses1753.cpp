/*
  CSES 1753 - String Matching
  https://cses.fi/problemset/task/1753
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
    if (i < r) { z[i] = min(r - i, z[i - l]); }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) { z[i]++; }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main() {
  fastio

  string s, p;
  cin >> s >> p;

  auto z = z_function(p + '$' + s);

  int cnt = 0;
  for (int i = p.size() + 1; i < z.size(); ++i)
    if (z[i] == p.size()) cnt++;
  cout << cnt << '\n';

  return 0;
}