/*
 * Contest : Beecrowd
 * Problem : 1329 - Cara ou Coroa
 * Link    : https://judge.beecrowd.com/pt/problems/view/1329
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve(int n) {
  int mary = 0, john = 0;
  while (n--) {
    int x; cin >> x;

    if (x) john++;
    else
      mary++;
  }
  cout << "Mary won " << mary << " times and John won " << john << " times\n";
}

int main() {
  fastio

  int n;
  while (cin >> n, n != 0) solve(n);

  return 0;
}