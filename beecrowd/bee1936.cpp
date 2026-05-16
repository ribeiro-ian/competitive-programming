/*
  Beecrowd 1936 - Fatorial
  https://judge.beecrowd.com/pt/problems/view/1936
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> fact = {1};

  while (fact.back() <= n) fact.push_back(fact.back() * fact.size());

  ll cnt = 0;
  while (n > 0) {
    auto it = upper_bound(fact.begin(), fact.end(), n);
    --it;
    cerr << '-' << *it << '\n';
    n -= *it;
    cnt++;
  }
  cout << cnt << '\n';

  return 0;
}