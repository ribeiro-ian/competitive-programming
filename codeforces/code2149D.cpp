#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  if (n <= 3) {
    cout << 0 << '\n';
    return;
  }

  int ans = 0;
  for (int i = 0; i < n - 2; ++i) {

    if (i == n - 3 && s[i] != s[i + 1] && s[i] == s[i + 2]) ans++;
  }

  cout << ans << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}