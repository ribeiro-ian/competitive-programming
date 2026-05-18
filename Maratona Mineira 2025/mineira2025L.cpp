/*
  Maratona Mineira 2025 - L - Lucro
  https://codeforces.com/group/YgJmumGtHD/contest/105936/problem/L
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int a, b, c;
  cin >> a >> b >> c;

  if (a * b == c) cout << "S\n";
  else
    cout << "N\n";

  return 0;
}