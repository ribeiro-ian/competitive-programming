/*
  Beecrowd 1403 - Meu Avô é Famoso
  https://judge.beecrowd.com/pt/problems/view/1403
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
void solve() {
  vector<int> freq(10'001);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x; cin >> x;
      freq[x]++;
    }
  }

  set<int> qtt;
  for (auto &i : freq) qtt.insert(i);

  auto second = qtt.rbegin();
  // 2 5 10 <-
  second++;
  // 2 5 <- 10

  for (int i = 1; i < freq.size(); ++i)
    if (freq[i] == *second) cout << i << ' ';
  cout << '\n';
}

int main() {
  fastio

  while (cin >> n >> m && n && m) solve();

  return 0;
}