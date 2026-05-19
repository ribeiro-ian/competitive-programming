/*
 * Contest : Beecrowd
 * Problem : 1551 - Frase Completa
 * Link    : https://judge.beecrowd.com/pt/problems/view/1551
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  string s;
  getline(cin, s);

  set<char> unique;
  for (auto &c : s) {
    if (c >= 'a' && c <= 'z') unique.insert(c);
  }

  cerr << unique.size() << '\n';
  if (unique.size() >= 26) cout << "frase completa\n";
  else if (unique.size() >= 13) cout << "frase quase completa\n";
  else
    cout << "frase mal elaborada\n";
}

int main() {
  fastio

  int tc; cin >> tc;
  cin.ignore();
  while (tc--) solve();

  return 0;
}