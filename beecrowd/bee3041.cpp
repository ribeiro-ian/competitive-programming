/*
 * Contest : Beecrowd
 * Problem : 3041 - Distribuição de Artigos
 * Link    : https://judge.beecrowd.com/pt/problems/view/3041
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  while (cin >> n, n) {
    vector<int> limite(n);

    for(auto& i : limite) cin >> i;
    sort(limite.rbegin(), limite.rend());

    int total = accumulate(limite.begin(), limite.end(), 0);
    int a; cin >> a;

    if (a > total) {
      cout << "Impossible\n";
      continue;
    }
    
    vector<int> revisores(n);
    int i = 0;

    while (a > 0) {
      if (revisores[i] < limite[i]) {
        revisores[i]++;
        a--;
        i = (i+1) % n;
      }
      else
        i = 0;
    }

    for (auto& i : revisores) 
      cout << i << '\n';
  }

  return 0;
}