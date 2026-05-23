/**
 * Contest : Beecrowd
 * Problem : 1245 - Botas Perdidas
 * Link    : https://judge.beecrowd.com/pt/problems/view/1245
 * Time    : O(N * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  while (cin >> n) {
    multiset<int> esq, dir;
    int cnt = 0;
    while (n--) {
      int m; char l;
      cin >> m >> l;

      if (l == 'E') {
        if (dir.count(m)) {
          cnt++;
          dir.erase(dir.find(m)); //logN
        }
        else
          esq.insert(m); // logN
      }
      else { // l == 'D'
        if (esq.count(m)) {
          cnt++;
          esq.erase(esq.find(m));
        }
        else
          dir.insert(m);
      }
    }
    cout << cnt << '\n';
  }

  return 0;
}