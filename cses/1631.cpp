/*
 * Contest : CSES Problem Set
 * Problem : 1631 - Reading Books
 * Link    : https://cses.fi/problemset/task/1631
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<ll> books(n);

  ll sum = 0, largest = 0;
  for (auto &i : books) {
    cin >> i;
    sum += i;
    largest = max(largest, i);
  }

  cout << (largest > sum - largest ? 2 * largest : sum) << '\n';

  return 0;
}
