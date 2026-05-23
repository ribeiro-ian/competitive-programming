/**
 * Contest : CSES Problem Set
 * Problem : 1676 - Road Construction
 * Link    : https://cses.fi/problemset/task/1676
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<int> p, sz;
int n, m, comp, maxi = 1;

int find(int x) { 
  if (x == p[x]) return x;
  return p[x] = find(p[x]);
}

void join(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) return;
  if (sz[a] < sz[b]) swap(a,b);

  p[b] = a;
  sz[a] += sz[b];
  comp--, maxi = max(maxi, sz[a]);
}

int main() {
  fastio

  cin >> n >> m;

  p.resize(n+1);
  sz.assign(n+1,1);
  iota(p.begin(), p.end(), 0);
  comp = n;

  while (m--) {
    int a, b;
    cin >> a >> b;

    join(a,b);
    cout << comp << ' ' << maxi << '\n';
  }

  return 0;
}