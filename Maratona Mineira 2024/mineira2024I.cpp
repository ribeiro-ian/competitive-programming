/*
  Maratona Mineira 2024 - I - Jazz
  https://codeforces.com/group/YgJmumGtHD/contest/528947/problem/I
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  const int MAX = 2e5+1;
  int n; cin >> n;
  vector<int> v(n), dp(MAX);
  
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n; i++) { // O(N)
    int x = v[i];

    int best = 0;
    for(int d = 1; d*d <= x; d++) { // O(raiz de N)
      if (x % d == 0) {
        best = max(best, dp[d]+1);
        best = max(best, dp[x/d]+1);
        cerr << '\t' << d << ' ' << x/d << '\n';
      }
    }
    dp[x] = best;
    cerr << x << ' ' << dp[x] << '\n';
    ans = max(ans, dp[x]);
  }
  cout << ans << '\n';

  return 0;
}