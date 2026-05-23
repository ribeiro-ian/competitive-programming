/**
 * Contest : Beecrowd
 * Problem : 2379 - Dança Indígena
 * Link    : https://judge.beecrowd.com/pt/problems/view/2379
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, e;
  cin >> n >> e;

  vector<int> inicial(n), indio(n), dir(n);
  for (int i = 0; i < n; ++i) {
    cin >> inicial[i] >> dir[i];
    indio[i] = inicial[n];
  }
  int cnt = 0;

  auto giveAnt = [&](int i, int d) {
    int ant = i-d;
    if (ant < 0) return n-1;
    if (ant >= n) return 0;
    return ant;
  };
  auto giveProx = [&](int i, int d) {
    int prox = i+d;
    if (prox < 0) return n-1;
    if (prox >= n) return 0;
    return prox;
  };

  return 0;
}