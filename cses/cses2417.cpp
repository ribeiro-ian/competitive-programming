/*
 * Contest : CSES
 * Problem : 2417 - Counting Coprime Pairs
 * Link    : https://cses.fi/problemset/task/2417
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<int> spf(1e6 + 1), cnt(1e6 + 1);

void crivo() {
  spf[1] = 1;
  for (int i = 2; i < spf.size(); ++i)
    if (!spf[i])
      for (int j = i; j < spf.size(); j += i)
        if (!spf[j]) spf[j] = i;
}

void factor(int x) {
  if (x == 1) cnt[x]++;

  while (x != 1) {
    cnt[spf[x]]++;

    while (spf[x] == spf[x / spf[x]]) x /= spf[x];

    x /= spf[x];
  }
}

int main() {
  fastio

  crivo();
  int n; cin >> n;
  vector<int> v(n);

  for (auto &i : v) {
    cin >> i;
    factor(i);
  }

  int ans = 0;
  for (auto &i : v) {
    if (spf[i] == i) { ans += n - cnt[i] - (i != 1); }
  }
  cout << ans << '\n';

  return 0;
}