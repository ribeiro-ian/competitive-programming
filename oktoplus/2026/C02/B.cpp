/*
  Beecrowd 1326 - Química
  https://judge.beecrowd.com/pt/problems/view/1326
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

map<string, pair<string, string>> mp;
ll n;

int rec(string p) {
  if (mp.find(p) == mp.end()) return 0;

  int x = rec(mp[p].first),
      y = rec(mp[p].second);
  if (x == 0 && y == 0) return 1;
  return x + y;
}
void solve() {
  if (!n) return;
  mp.clear();

  string x, y, z, aux, last;
  while (n--) {
    cin >> x >> aux >> y >> aux >> z;
    mp[z] = {x, y};
    last = z;
  }

  cout << last << " requires " << max(rec(z) - 1, 1) << " containers\n";
}

int main() {
  fastio

  while (cin >> n) solve();

  return 0;
}