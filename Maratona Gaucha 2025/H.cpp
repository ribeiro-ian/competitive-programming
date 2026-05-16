#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string str; cin >> str;

  ll sum = 0;
  for (auto &c : str) {
    int v = c - 'a';

    sum += ('z' - v) - 'a' + 1;
  }

  cout << sum << '\n';

  return 0;
}