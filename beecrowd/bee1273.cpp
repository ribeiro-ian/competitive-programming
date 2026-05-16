/*
  Beecrowd 1273 - Justificador
  https://judge.beecrowd.com/pt/problems/view/1273
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, first = true;
void solve() {
  if (!n) return;
  if (!first) cout << '\n';
  first = false;

  int maxi = 0;
  vector<string> words(n);
  for (auto &w : words) {
    cin >> w;
    maxi = max(maxi, (int)w.size());
  }

  for (auto &w : words) cout << setw(maxi) << w << '\n';
}

int main() {
  fastio

  while (cin >> n, n) solve();

  return 0;
}