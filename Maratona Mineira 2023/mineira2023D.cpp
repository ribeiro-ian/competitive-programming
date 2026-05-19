/*
 * Contest : Maratona Mineira 2023
 * Problem : D - Adedanha
 * Link    : https://codeforces.com/group/YgJmumGtHD/contest/446227/problem/D
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  
  int n; cin >> n;
  vector<int> v(n);
  
  int soma = 0;
  for(int i = 1; i < n; ++i){
    cin >> v[i];
    soma += v[i];
  }
  
  for (int i = 0; i < n; ++i) {
    int d = 0;
    while (d <= 20 && (soma + d) % n != i) {
      d++;
    }
    if (d > 20) cout << "-1\n";
    else cout << d << '\n';
  }
  
  return 0;
}