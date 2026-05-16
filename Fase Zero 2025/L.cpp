#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll m; cin >> m;

  cout << ceil(log2(m * 1000000 * 8)) << endl;

  return 0;
}