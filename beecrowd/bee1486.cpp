/**
 * Contest : Beecrowd
 * Problem : 1486 - Circuito Bioquímico Digital
 * Link    : https://judge.beecrowd.com/pt/problems/view/1486
 * Time    : O(N * P)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int p, n, c;
  while (cin >> p >> n >> c && p && n && c) {
    vector<int> tam(p);    
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < p; ++j) {
        int x; cin >> x;

        if (i >= n-1) {
          tam[j] += x;
          cnt += (tam[j] >= c);
        }
        else {
          if (x == 0) {
            cnt += (tam[j] >= c);
            tam[j] = 0;
          }
          else
            tam[j]++;
        }
      }
    }
    
    cout << cnt << '\n';
  }

  return 0;
}