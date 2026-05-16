/*
  Beecrowd 2653 - Dijkstra
  https://judge.beecrowd.com/pt/problems/view/2653
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  set<string> s;
  string str;
  while (cin >> str) { s.insert(str); }

  cout << s.size() << endl;

  return 0;
}