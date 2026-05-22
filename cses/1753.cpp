/*
 * Contest : CSES Problem Set
 * Problem : 1753 - String Matching
 * Link    : https://cses.fi/problemset/task/1753
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<int> pi(string s) {
  vector<int> p(s.size());
  for (int i = 1, j = 0; i < s.size(); ++i) {
    while (j > 0 && s[j] != s[i]) j = p[j - 1];
    if (s[j] == s[i]) j++;
    p[i] = j;
  }
  return p;
}

int kmp(string &t, string &s) {
  vector<int> p = pi(s);
  int cnt = 0;

  for (int i = 0, j = 0; i < t.size(); ++i) {
    while (j > 0 && s[j] != t[i]) j = p[j - 1];
    if (s[j] == t[i]) j++;
    if (j == s.size()) cnt++;
  }
  return cnt;
}

int main() {
  fastio

  string t, s;
  cin >> t >> s;
  cout << kmp(t, s) << '\n';

  return 0;
}