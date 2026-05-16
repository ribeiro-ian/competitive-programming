/*
  OBI 2025 - Fase 1 - Festa Junina
  https://neps.academy/br/exercise/3124
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int e, s, l, res = -1;
  cin >> e >> s >> l;

  if (s > e && l > e) res = 2 * (max(s, l) - e);
  else if (l < e && s < e) res = 2 * (e - min(s, l));
  else
    res = 2 * (abs(s - e) + abs(l - e));

  cout << res << '\n';

  return 0;
}