/*
 * Contest : Maratona Mineira 2019
 * Problem : K - Cobra de Dominós
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/102223/problem/K
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll N; cin >> N;
  ll E = (N + 1) * (N + 2) / 2;

  if (N % 2) E -= N / 2;

  cout << E << '\n';

  return 0;
}