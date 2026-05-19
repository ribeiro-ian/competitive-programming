/*
 * Contest : Beecrowd
 * Problem : 1397 - Jogo do Maior
 * Link    : https://judge.beecrowd.com/pt/problems/view/1397
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
void solve() {
  int a = 0, b = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;

    if (x > y) a++;
    else if (y > x) b++;
  }
  cout << a << ' ' << b << '\n';
}

int main() {
  fastio

  while (cin >> n, n) solve();

  return 0;
}