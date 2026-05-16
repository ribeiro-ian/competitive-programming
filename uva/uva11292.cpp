/*
  UVA 11292 - Dragon of Loowater
  https://vjudge.net/problem/UVA-11292
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve(int n, int m) {
  vector<int> h(n), k(m);

  for (auto &i : h) cin >> i;
  sort(h.begin(), h.end());

  for (auto &i : k) cin >> i;
  sort(k.begin(), k.end());

  int i = 0, j = 0, gold = 0;
  while (i < n && j < m) {
    if (k[j] >= h[i]) {
      gold += k[j];
      i++;
    }
    j++;
  }
  if (i < n) cout << "Loowater is doomed!\n";
  else
    cout << gold << '\n';
}

int main() {
  fastio

  int n, m;
  queue<int> q;
  while (cin >> n >> m, n && m) solve(n, m);

  return 0;
}