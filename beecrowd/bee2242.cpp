/*
  Beecrowd 2242 - Huaauhahhuahau
  https://judge.beecrowd.com/pt/problems/view/2242
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string s, v; cin >> s;
  for (auto &c : s)
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') v.push_back(c);
  string r = v;
  reverse(r.begin(), r.end());

  cout << (r == v ? 'S' : 'N') << '\n';

  return 0;
}