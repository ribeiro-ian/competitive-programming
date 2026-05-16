/*
  Beecrowd 1323 - Feynman
  https://judge.beecrowd.com/pt/problems/view/1323
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int MAX = 100 + 1;
  vector<int> prefix_sum(MAX);

  for (int i = 1; i < MAX; i++) // O(1) prefix_sum[i] = prefix_sum[i - 1] + i * i;

  int n;

  // Complexidade O(MAX+k), k = num de entradas
  while (1) {
    cin >> n;

    if (!n) break;

    printf("%i\n", prefix_sum[n]);
  }

  return 0;
}