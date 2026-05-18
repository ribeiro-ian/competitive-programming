/*
  Beecrowd 3351 - Clickbait
  https://judge.beecrowd.com/pt/problems/view/3351
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<pair<ll, ll>> v; // {primero momento, tempo até voltar a assistir dnv}
ll n, k;

bool valid(ll x) {
  ll cnt = 0;
  for (auto &[primeiro, tempo] : v) {
    if (primeiro <= x) cnt += 1 + (x - primeiro) / tempo;
    if (cnt >= k) return true;
  }
  return cnt >= k;
}

ll bs() {
  ll l = 1, r = 2e18 + 1;

  while (l <= r) {
    ll m = l + (r - l) / 2;

    if (valid(m)) r = m - 1;
    else
      l = m + 1;
  }
  return l;
}

int main() {
  fastio

  cin >> n >> k;
  v.resize(n);
  for (auto &[primeiro, tempo] : v) cin >> primeiro >> tempo;

  cout << bs() << '\n';

  return 0;
}