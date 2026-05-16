/*
  Beecrowd 1393 - Lajotas Hexagonais
  https://judge.beecrowd.com/pt/problems/view/13930
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;
  const int MAX = 40+1;

  vector<int> fib(MAX);

  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 2;

  for (int i = 3; i < MAX; i++) { fib[i] = fib[i - 1] + fib[i - 2]; }

  while (1) {
    cin >> n;

    if (!n) break;

    printf("%i\n", fib[n]);
  }

  return 0;
}