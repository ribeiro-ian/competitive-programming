/*
  Codeforces 588A - Duff and Meat
  https://codeforces.com/problemset/problem/588/A
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<int> pre(n + 1), p(n + 1), menoresId;

  for (int i = 1; i <= n; i++) {
    cin >> pre[i] >> p[i];

    if (menoresId.empty()) menoresId.push_back(i);
    if (p[i] < p[menoresId.back()]) menoresId.push_back(i);
    pre[i] += pre[i - 1];
  }
  menoresId.push_back(n + 1);

  int ans = 0;
  for (int i = 1, j = 0; i <= n; ++j) {
    int curr = menoresId[j], prox = menoresId[j + 1];
    int qtde = pre[prox - 1] - pre[i - 1];

    ans += p[curr] * qtde;
    i = prox;
  }
  cout << ans << '\n';

  return 0;
}