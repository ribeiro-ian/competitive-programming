/**
 * Contest : Beecrowd
 * Problem : 1225 - Coral Perfeito
 * Link    : https://judge.beecrowd.com/pt/problems/view/1225
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  
  int n;
  while (cin >> n) {
    vector<ll> v(n);
    ll sum = 0;
    
    // se a cada compasso, um v [i] aumemta +1
    // e um v[i] diminui -1, soma total sem mantém
    for (auto& i : v) {
      cin >> i;
      sum += i;
    }

    // se a soma se mantém e no final todos v[i]
    // devem ser iguais, então temos que o
    // n*v[i] = sum, logo sum deve ser multiplo de n
    if (sum % n != 0) 
      cout << -1 << '\n';
    else {
      // para n*v[i] = sum, logo v[i] = sum/n
      ll cnt = 0, media = sum/n;

      // contar quantos compassos para v[i] ser igual a média
      // soh precisar contar uma das operações (+1 ou -1)
      for (auto& i : v)
        if (i < media)
          cnt += media - i;

      cout << cnt+1 << '\n';
    }
  }

  return 0;
}