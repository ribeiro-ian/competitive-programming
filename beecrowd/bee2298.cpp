/*
  Beecrowd 2298 - Mini-Poker
  https://judge.beecrowd.com/pt/problems/view/2298
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int sol() {
  int n = 5;

  vector<int> cartas(n);
  map<int, int> freq;

  for (auto& i : cartas) {
    cin >> i;
    freq[i]++;
  }
  sort(cartas.begin(), cartas.end());
  int dif = freq.size();

  // testar se tem sequencia primeiro
  if (dif == 5) {
    bool temSequencia = true;
    for (int i = 0; i < n-1; i++) {
      if (cartas[i+1] - cartas[i] != 1) {
        temSequencia = false;
        break;
      }
    }
    if (temSequencia) return cartas[0] + 200;
    return 0;
  }

  // 2 numeros diferentes = 1 quadra ou 1 trinca + 1 par
  if (dif == 2) {
    for (auto [num, qtd] : freq) {
      if (qtd == 4) return num + 180;  // quadra
      if (qtd == 3) return num + 160;  // trinca + par
    }
  }

  // 3 numeros diferentes = 1 trinca ou 2 pares
  if (dif == 3) {
    for (auto [num, qtd] : freq) 
      if (qtd == 3) return num + 140; // trinca

    int x = 0, y = 13;
    for (auto [num, qtd] : freq) {
      if (qtd == 2) {
        x = max(x, num);
        y = min(y, num);
      }
    }
    // cerr << "x = " << x << " y = " << y << '\n';
    return 3*x + 2*y + 20;
  }

  // 4 numeros diferentes = 1 par
  if (dif == 4)
   for (auto [num, qtd] : freq)
    if (qtd == 2)
      return num;

  return -1;   
}

int main() {
  fastio

  int tc; cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    cout << "Teste " << i << '\n';
    cout << sol() << "\n\n";
  }

  return 0;
}