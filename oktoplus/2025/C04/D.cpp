/*
  Bee 1260 - Espécies de Madeira
  https://judge.beecrowd.com/pt/problems/view/1260
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  map<string, int> tree;
  string str;

  int tc; cin >> tc;
  cin.ignore();
  getline(cin, str);

  while (tc--) {
    double total = 0;
    tree.clear();

    while (getline(cin, str)) {
      if (str.empty()) break;

      total++;

      tree[str] += 1;
    }

    for (auto t : tree) { printf("%s %.4f\n", t.first.c_str(), 100 * t.second / total); }

    if (tc != 0) printf("\n");
  }

  return 0;
}
