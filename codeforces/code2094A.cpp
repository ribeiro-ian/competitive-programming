/*
 * Contest : Codeforces
 * Problem : 2094A - Trippi Troppi
 * Link    : https://codeforces.com/contest/2094/problem/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) {
    string str, ans = "";
    for (int i = 0; i < 3; i++) {
      cin >> str;
      ans += str[0];
    }

    cout << ans << "\n";
  }

  return 0;
}