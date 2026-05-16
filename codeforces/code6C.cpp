/*
  Codeforces 6C - Alice, Bob and Chocolate
  https://codeforces.com/problemset/problem/6/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<int> t(n);
  for (auto &i : t) cin >> i;

  int a = 0, b = 0,
      l = 0, r = n - 1;
  while (l <= r) {
    if (a <= b) a += t[l++];
    else
      b += t[r--];
  }
  cout << l << ' ' << n - 1 - r << '\n';

  return 0;
}