/*
  CSES 1068 - Weird Algorithm
  https://cses.fi/problemset/task/1068
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ull n; cin >> n;
  while (n > 1) {
    cout << n << ' ';

    if (n % 2) n = n * 3 + 1;
    else
      n /= 2;
  }

  cout << n << '\n';

  return 0;
}