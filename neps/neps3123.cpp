/*
 * Contest : OBI 2025 - Fase 1
 * Problem : Fila
 * Link    : https://neps.academy/br/exercise/3123
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<int> a(n);

  for (auto &i : a) cin >> i;

  int maxi = a.back(), ans = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] > maxi) maxi = a[i];
    else
      ans++;
  }
  cout << ans << '\n';

  return 0;
}