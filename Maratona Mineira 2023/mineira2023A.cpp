/*
 * Contest : Maratona Mineira 2023
 * Problem : A - Elemento X
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/446227/problem/A
 * Time    : O(1)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    fastio

  vector<int> v(5);
  for(int i = 1; i <= 4; ++i)
    cin >> v[i];

  for (int i = 1; i <= 4; ++i) {
    bool achou = true;
    for (int j = 1; j <= 4; j++) {
      if (i==j) continue;

      if (j < i) {
        if (j + v[j] != i) achou = false;
      }
      else {
        if (j - v[j] != i) achou = false;
      }
    }

    if (achou) {
      cout << i << '\n';
      return 0;
    }
  }

  return 0;
}