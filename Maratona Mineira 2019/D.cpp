/*
 * Contest : Maratona Mineira 2019
 * Problem : D - Prêmios da mineira
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/102223/problem/D
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

struct Time {
  int i, d, t;
};

bool cmp(Time a, Time b) {
  if (a.d != b.d) return a.d > b.d;
  return a.t < b.t;
}

int main() {
  fastio

  int n, k;
  cin >> n >> k;
  vector<Time> v(n);
  for (int i = 0; i < n; ++i) { cin >> v[i].i >> v[i].d >> v[i].t; }
  sort(v.begin(), v.end(), cmp);

  cout << v[k - 1].i << '\n';

  return 0;
}