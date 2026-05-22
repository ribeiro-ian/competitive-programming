/*
 * Contest : CSES Problem Set
 * Problem : 2165 - Tower of Hanoi
 * Link    : https://cses.fi/problemset/task/2165
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<pair<int, int>> moves;
// move de A para B
void move(int n, int a, int b, int c) {
  if (n == 1)
    moves.push_back({a, b});
  else {
    move(n - 1, a, c, b);
    move(1, a, b, c);
    move(n - 1, c, b, a);
  }
}

int main() {
  fastio

  int n; cin >> n;
  move(n, 1, 3, 2);

  cout << moves.size() << '\n';
  for (auto &[a, b] : moves) cout << a << ' ' << b << '\n';

  return 0;
}