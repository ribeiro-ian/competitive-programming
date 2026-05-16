#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  string s, t;

  cin >> s; // estado isolado
  cin >> t; // cond normais

  int colapsa = 0,
      super = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*') super++;
    if (s[i] == '*' && t[i] != '*') colapsa++; 
  }

  printf("%.2f\n", (double)colapsa / (double)super);

  return 0;
}