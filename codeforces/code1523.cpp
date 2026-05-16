/*
  Beecrowd 1523 - Estacionamento Linear
  https://judge.beecrowd.com/pt/problems/view/1523
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;

int main() {
  fastio

  int n, k, x, y;

  while (1) {
    scanf("%i %i", &n, &k);

    if (!n) break;

    stack<pii> est;
    bool flag = true;

    for (int i = 0; i < n; i++) {
      scanf("%i %i", &x, &y);

      while (!est.empty() and est.top().second <= x) est.pop();

      if (est.size() >= k) flag = false;
      else {
        if (est.empty())
          est.push({x, y});
        else if (est.top().second > y)
          est.push({x, y});
        else
          flag = false;
      }
    }

    printf("%s\n", flag ? "Sim" : "Nao");
  }

  return 0;
}
