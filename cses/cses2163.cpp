/*
 * Contest : CSES
 * Problem : 2163 - Josephus Problem II
 * Link    : https://cses.fi/problemset/task/2163
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int N = 2e5 + 1;
vector<bool> done(N, false);
vector<int> ans(N);
int n, k;

int pos(int x) {
  return (x % n == 0 ? n : x % n);
}

int main() {
  fastio

  cin >> n >> k;
  int st = ((1 + k) % n ? (1 + k) % n : n);

  cout << '\n';

  return 0;
}