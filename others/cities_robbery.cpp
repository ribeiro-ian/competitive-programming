/*
 * Contest : CS Academy
 * Problem : Cities Robbery
 * Link    : https://vjudge.net/problem/CSAcademy-cities-robbery
 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll ans = 0, x, k;
void best(vector<pair<ll, ll>> &a, vector<ll> &preA, vector<pair<ll, ll>> &b, vector<ll> &preB) {
  for (int i = 0; i <= (int)a.size(); ++i) {
    ll distA = (i == 0) ? 0 : a[i - 1].first;
    // i=0 => go just to one side
    ll spent = 2 * distA;

    if (spent > k) break;
    ll rest = k - spent;

    int j = upper_bound(b.begin(), b.end(), pair{rest, LLONG_MAX}) - b.begin();
    ans = max(ans, preA[i] + preB[j]);
  }
}

int main() {
  fastio

  int n;
  cin >> n >> x >> k;

  vector<pair<ll, ll>> l, r; // {dist, val}
  for (int i = 0; i < n; ++i) {
    ll xi, w;
    cin >> xi >> w;

    if (xi < x)
      l.push_back({x - xi, w});
    else
      r.push_back({xi - x, w});
  }

  // sort by distance
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());

  auto makePrefix = [](vector<pair<ll, ll>> &v) {
    vector<ll> pre(v.size() + 1, 0);
    for (int i = 0; i < v.size(); ++i) pre[i + 1] = pre[i] + v[i].second;
    return pre;
  };

  vector<ll> preL = makePrefix(l);
  vector<ll> preR = makePrefix(r);

  best(l, preL, r, preR); // vai esquerda primeiro, depois direita
  best(r, preR, l, preL); // vai direita primeiro, depois esquerda
  cout << ans << '\n';

  return 0;
}