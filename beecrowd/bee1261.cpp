/*
 * Contest : Beecrowd
 * Problem : 1261 - Pontos de Feno
 * Link    : https://judge.beecrowd.com/pt/problems/view/1261
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int m, n;
void solve() {
  map<string, ll> mp;
  while (m--) {
    string s;
    ll x;
    cin >> s >> x;
    mp[s] = x;
  }

  string word;
  while (n--) {
    ll sum = 0;
    while (cin >> word, word != ".") sum += mp[word];
    cout << sum << '\n';
  }
}

int main() {
  fastio

  while (cin >> m >> n) solve();

  return 0;
}