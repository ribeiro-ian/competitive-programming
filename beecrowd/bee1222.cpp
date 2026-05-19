/*
 * Contest : Beecrowd
 * Problem : 1222 - Concurso de Contos
 * Link    : https://judge.beecrowd.com/pt/problems/view/1222
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, l, c;
  string word;

  while (scanf("%i%i%i", &n, &l, &c) != EOF) {

    int line = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
      cin >> word;

      cnt += word.size();
      if (cnt > c) {
        cnt = word.size();
        line++;
      }
      cnt++;
    }

    line += cnt > 1 ? 1 : 0;
    printf("%i\n", line / l + (line % l ? 1 : 0));
  }

  return 0;
}