/*
  Beecrowd 2292 - Painel LED
  https://judge.beecrowd.com/pt/problems/view/2292
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

char alternar(char c) {
  return c == 'X' ? 'O' : 'X';
}

int main() {
  fastio

  ll c, tc;

  cin >> tc;
  while (tc--) {
    string led, ans;

    cin >> led >> c;

    ans += c % 2 == 0 ? led[0] : alternar(led[0]);

    for (int i = 1; i < led.size(); i++) {
      if (ans[i - 1] == 'X' && led[i - 1] == 'O') c++;

      c = c / 2;

      ans += c % 2 == 0 ? led[i] : alternar(led[i]);
    }

    printf("%s\n", ans.c_str());
  }

  return 0;
}
