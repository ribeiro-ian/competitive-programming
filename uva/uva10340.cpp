/*
 * Contest : UVA
 * Problem : 10340 - All in All
 * Link    : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1281
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string s, t;

  while (cin >> s >> t) {

    int i = 0;
    for (auto &c : t) {
      if (c == s[i]) { i++; }
    }

    printf("%s\n", i == s.size() ? "Yes" : "No");
  }

  return 0;
}