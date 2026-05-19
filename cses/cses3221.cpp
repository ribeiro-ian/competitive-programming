/*
 * Contest : CSES
 * Problem : 3221 - Sliding Window Minimum
 * Link    : https://cses.fi/problemset/task/3221
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
using pii = pair<ll, ll>;

ll a, b, c;
deque<ll> q;

inline ll calc(ll x) {
  return (a * x + b) % c;
}

void add(ll x) {
  while (!q.empty() && q.back() > x) q.pop_back();
  q.push_back(x);
}

void remove(ll x) {
  if (!q.empty() && q.front() == x) q.pop_front();
}

int main() {
  fastio

  ll n, k, x;
  cin >> n >> k;
  cin >> x >> a >> b >> c;

  q.push_back(x);
  ll ans, last = x;
  for (int i = 1; i < k; ++i) {
    x = calc(x);
    add(x);
  }
  ans = q.front();

  for (int i = k; i < n; ++i) {
    // remove last element;
    remove(last);
    last = calc(last);

    // new element
    x = calc(x);
    add(x);

    ans = (ans ^ q.front());
  }
  cout << ans << '\n';

  return 0;
}
