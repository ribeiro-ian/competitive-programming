/*
  Beecrowd 1457 - Oráculo de Alexandria
  https://judge.beecrowd.com/pt/problems/view/1457
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll t; cin >> t;
  while (t--) {
    string str; cin >> str;
    string num = "";

    ll n, k = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] != '!') num += str[i];
      else {
        k = str.size() - i;
        break;
      }
    }

    n = stoi(num);
    ll ans = 1;
    for (int i = 0; i <= n; ++i) {
      if (n - i * k <= 0) break;
      ans *= (n - i * k);
    }
    cout << ans << '\n';
  }

  return 0;
}