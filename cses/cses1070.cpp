/*
 * Contest : CSES
 * Problem : 1070 - Permutations
 * Link    : https://cses.fi/problemset/task/1070
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;

  if (n <= 3 && n > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }

  for (int i = n - 1; i >= 1; i -= 2) cout << i << ' ';

  for (int i = n; i >= 1; i -= 2) cout << i << ' ';

  cout << '\n';

  return 0;
}