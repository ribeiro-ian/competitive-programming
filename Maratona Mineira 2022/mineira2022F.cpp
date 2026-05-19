/*
 * Contest : Maratona Mineira 2022
 * Problem : F - Caindo de Paraquedas
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/F
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll g; cin >> g;
  string str; cin >> str;

  ll sum = 0, e = 0, d = 0;
  for (auto &c : str) {
    if (c == 'D') {
      sum += g;
    } else
      sum -= g;

    e = min(e, sum);
    d = max(d, sum);

    if (d + abs(e) >= 360 || sum >= 360) {
      cout << "S\n";
      return 0;
    }
  }

  cout << "N\n";

  return 0;
}