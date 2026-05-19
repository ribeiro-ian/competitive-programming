/*
 * Contest : Codeforces
 * Problem : 990B - Micro-World
 * Link    : https://codeforces.com/contest/990/problem/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  int cnt = n;
  for (int i = 0; i < n; i++) {
    int aux = upper_bound(a, a + n, a[i]) - a;

    if (aux < n && a[aux] - a[i] <= k) cnt--;
  }

  cout << cnt << "\n";

  return 0;
}
