/*
  Bee 1162 - Organizador de Vagões
  https://judge.beecrowd.com/pt/problems/view/1162
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  int tc, n; cin >> tc;

  while (tc--) {
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++)
        if (v[i] > v[j]) {
          swap(v[i], v[j]);
          cnt++;
        }
    }

    printf("Optimal train swapping takes %i swaps.\n", cnt);
  }

  return 0;
}
