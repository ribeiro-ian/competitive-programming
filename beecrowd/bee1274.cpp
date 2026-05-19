/*
 * Contest : Beecrowd
 * Problem : 1274 - P-Networks
 * Link    : https://judge.beecrowd.com/pt/problems/view/1274
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n;
void solve() {
  vector<int> alvo(n+1), pos(n+1), cur(n+1);

  bool flag = false;
  vector<int> cnt(n+1, 0);
  
  for (int i = 1; i <= n; ++i) {
    cin >> alvo[i];
    cnt[alvo[i]]++;
    if (cnt[alvo[i]] > 1) flag = true;
  }
  
  if (flag) {
    cout << "No solution\n";
    return;
  }
  
  for (int i = 1; i <= n; ++i)
    cur[i] = i, pos[i] = i;
  
  vector<int> inv(n+1);
  for (int i = 1; i <= n; ++i) inv[alvo[i]] = i;
  
  vector<int> cursos;
  for (int k = 1; k <= n; ++k) {
    int p = pos[inv[k]];
    while (p > k) {
      int f1 = cur[p-1], f2 = cur[p];
      cur[p-1] = f2; cur[p] = f1;
      pos[f1] = p;   pos[f2] = p-1;
      cursos.push_back(p-1);
      p--;
    }
  }
  
  cout << cursos.size();
  for (auto& s : cursos) cout << ' ' << s;
  cout << '\n';
}

int main() {
  fastio
  
  while (cin >> n, n) solve();
  
  return 0;
}