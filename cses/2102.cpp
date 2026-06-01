/**
 * Contest : CSES Problem Set
 * Problem : 2102 - Finding Patterns
 * Link    : https://cses.fi/problemset/task/2102
 * Time    : O(K * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

//O(N logN)
vector<int> build_sa(string s) {
  s += "$";
  int n = s.size();
  vector<int> sa(n), r(n), nr(n);
  iota(sa.begin(), sa.end(), 0);

  // ordena pelos primeiros caracteres
  sort(sa.begin(), sa.end(), [&](int i, int j) { return s[i] < s[j]; });

  r[sa[0]] = 0;
  for (int i = 1; i < n; i++)
    r[sa[i]] = r[sa[i-1]] + (s[sa[i]] != s[sa[i-1]]);

  // dobra o tamanho do prefixo comparado
  for (int k = 1; k < n; k <<= 1) {
    sort(sa.begin(), sa.end(), [&](int i, int j) {
      if (r[i] != r[j]) return r[i] < r[j];
      int ri = (i + k < n) ? r[i + k] : -1;
      int rj = (j + k < n) ? r[j + k] : -1;
      return ri < rj;
    });

    nr[sa[0]] = 0;
    for (int i = 1; i < n; i++)
      nr[sa[i]] = nr[sa[i-1]] + ((r[sa[i]] != r[sa[i-1]]) ||
        ((sa[i]+k < n ? r[sa[i]+k] : -1) != (sa[i-1]+k < n ? r[sa[i-1]+k] : -1)));

    r = nr;
    if (r[sa[n-1]] == n-1) break; // ranks todos distintos
  }

  return sa; // último elemento é o '$' (n-1)
}

// Busca padrão p: retorna {primeira, última} posição no SA
// O(|p| * logN)
pair<int,int> find_pattern(string &s, vector<int> &sa, string &p) {
  int n = s.size(), m = p.size();
  int L = 0, R = n-1;

  // lower_bound
  int first = -1;
  while (L <= R) {
    int mid = (L + R) / 2;
    int cmp = s.compare(sa[mid], m, p);
    if (cmp >= 0) {
      if (cmp == 0) first = mid;
      R = mid - 1;
    }
    else L = mid + 1;
  }
  if (first == -1) return {-1, -1};

  // upper_bound
  L = 0, R = n-1;
  int last = first;
  while (L <= R) {
    int mid = (L + R) / 2;
    int cmp = s.compare(sa[mid], m, p);
    if (cmp <= 0) {
      if (cmp == 0) last = mid;
      L = mid + 1;
    }
    else R = mid - 1;
  }
  return {first, last};
}

int main() {
  fastio

  string s; cin >> s;
  auto sa = build_sa(s);
  s += '$';

  int k; cin >> k;
  while (k--) {
    string p; cin >> p;

    auto ans = find_pattern(s, sa, p);
    cout << (ans.first !=-1 ? "YES" : "NO") << '\n';
  }

  return 0;
}