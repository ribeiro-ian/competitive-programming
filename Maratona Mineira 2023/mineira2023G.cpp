/*
 * Contest : Maratona Mineira 2023
 * Problem : G - Jogo dos Copos
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/446227/problem/G
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int comecou = 0, pos = 2;
  int n, a, b;
  cin >> n;

  while (n--) {
    cin >> a >> b;

    if (pos == a)
      pos = b;
    else if (pos == b)
      pos = a;
  }
  cout << pos << '\n';

  return 0;
}