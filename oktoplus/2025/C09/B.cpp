/*
  Codeforces 2074A - Draw a Square
  https://codeforces.com/problemset/problem/2074/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  int tc, l, r, d, u;

  cin >> tc;
  while (tc--) {
    cin >> l >> r >> d >> u;

    if (l == r && d == u && l == d) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }

  return 0;
}