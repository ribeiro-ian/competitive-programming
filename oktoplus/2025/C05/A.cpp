/*
  Beecrowd 1318 - Bilhetes Falsos
  https://judge.beecrowd.com/pt/problems/view/1318
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, m, x;

  while (1) {
    scanf("%i %i", &n, &m);

    if (!n) break;

    map<int, int> tickets;
    for (int i = 0; i < m; i++) {
      scanf("%i", &x);
      tickets[x]++;
    }

    int cnt = 0;
        for(auto t : tickets if(t.second > 1) cnt++;
        

        printf("%i\n", cnt);
  }

  return 0;
}
