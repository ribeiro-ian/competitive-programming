/*
  Beecrowd 2845 - Festa no Polo Norte
  https://judge.beecrowd.com/pt/problems/view/2845
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const int N = 1e5 + 1;
  int n; cin >> n;
  vector<int> v(n), div(N);
  for (auto &i : v) {
    cin >> i;
    if (i == 1) continue;

    int j = i;
    while (j < N) {
      div[j]++;
      j += i;
    }
  }
  sort(v.begin(), v.end());
  for (int i = v.back() + 1; i < N; ++i) {
    if (div[i] < 1) {
      cout << i << '\n';
      break;
    }
  }

  return 0;
}