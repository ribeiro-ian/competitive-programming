/*
  Codeforces 628A - Tennis Tournament
  https://codeforces.com/problemset/problem/628/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, b, p, ans = 0;
  cin >> n >> b >> p;

  int towels = n * p;
  while (n > 1) {
    int matches = n / 2;
    ans += (2 * b + 1) * matches;
    if (n % 2) {
      n = n - matches;
    }
    else {
      n /= 2;
    }
  }

  cout << ans << " " << towels << '\n';

  return 0;
}