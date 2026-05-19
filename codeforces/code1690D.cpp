/*
 * Contest : Codeforces
 * Problem : 1690D - Black and White Stripe
 * Link    : https://codeforces.com/problemset/problem/1690/D
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n, k;
  cin >> n >> k;
  string str; cin >> str;

  int l = 0, r = 0, cnt = 0, ans = n;
  while (r < k) {
    if (str[r] == 'W') cnt++;
    r++;
  }
  ans = min(ans, cnt);

  while (r < n) {
    if (str[l] == 'W') cnt--;
    if (str[r] == 'W') cnt++;
    r++;
    l++;
    ans = min(ans, cnt);
  }

  cout << ans << endl;
}

int main() {
  fastio

  int tc; cin >> tc;

  while (tc--) { solve(); }

  return 0;
}