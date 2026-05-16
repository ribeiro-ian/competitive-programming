/*
  Beecrowd 1933 - Tri-du
  https://judge.beecrowd.com/pt/problems/view/1933
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int a, b;
  cin >> a >> b;

  cout << max(a, b) << '\n';

  return 0;
}