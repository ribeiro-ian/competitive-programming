/*
  Codeforces 2074B - The Third Side
  https://codeforces.com/contest/2074/problem/B
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  int tc, n;
  scanf("%i", &tc);

  while (tc--) {
    scanf("%i", &n);
    vector<int> v(n);

    for (int i = 0; i < n; i++) scanf("%i", &v[i]);

    sort(v.begin(), v.end());

    ll ans = v[0];
    for (int i = 1; i < n; i++) { ans = ans + v[i] - 1; }

    printf("%lli\n", ans);
  }

  return 0;
}