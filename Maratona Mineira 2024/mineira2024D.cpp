/*
  Maratona Mineira 2024 - D - Leite das crianças
  https://codeforces.com/group/YgJmumGtHD/contest/528947/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, l;
  cin >> n >> l;
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  sort(v.rbegin(), v.rend());

  int aux = 0, i = 0, cnt = 0;
  while (i < n && aux < l) {
    aux += 100 - v[i];
    if (aux <= l) {
      i++;
      cnt++;
    }
  }
  cout << cnt << '\n';

  return 0;
}