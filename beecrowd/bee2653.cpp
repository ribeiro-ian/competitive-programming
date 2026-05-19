/*
 * Contest : Beecrowd
 * Problem : 2653 - Dijkstra
 * Link    : https://judge.beecrowd.com/pt/problems/view/2653
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string str;
  set<string> s;
  while (cin >> str) { s.insert(str); }
  cout << (int)s.size() << '\n';

  return 0;
}