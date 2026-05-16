/*
  Codeforces 2218C - The 67th Permutation Problem
  https://codeforces.com/contest/2218/problem/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n; cin >> n;

  for (int i = 1; i <= 3 * n; ++i) {
    cout << i << " \n"[i == 3 * n];
    if (i % n == 0 && i != 3 * n) cout << "| ";
  }
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}