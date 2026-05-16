/*
  Beecrowd 1836 - Pokémon!
  https://judge.beecrowd.com/pt/problems/view/1836
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int caseNum = 0;
void solve() {
  vector<string> atr = {"HP", "AT", "DF", "SP"};
  ll L, Bs, IV, EV;
  string pokemon;

  cin >> pokemon >> L;
  cout << "Caso #" << ++caseNum << ": " << pokemon << " nivel " << L << '\n';

  for (int i = 0; i < 4; ++i) {
    cin >> Bs >> IV >> EV;
    cout << atr[i] << ": ";
    if (i == 0) {
      cout << (int)((IV + Bs + sqrt(EV) / 8 + 50) * L) / 50 + 10 << '\n';
    } else
      cout << (int)((IV + Bs + sqrt(EV) / 8) * L) / 50 + 5 << '\n';
  }
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}