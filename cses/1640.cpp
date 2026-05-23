/**
 * Contest : CSES Problem Set
 * Problem : 1640 - Sum of Two Values
 * Link    : https://cses.fi/problemset/task/1640
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n, x;
  cin >> n >> x;

  vector<pair<ll, ll>> arr(n);
  for (int i = 0; i < n; ++i) {
    ll a; cin >> a;
    arr[i] = {a, i + 1};
  }
  sort(arr.begin(), arr.end());

  int i = 0, j = n - 1;
  while (i < j) {
    ll sum = arr[i].first + arr[j].first;
    if (sum > x) j--;
    else if (sum < x) i++;
    else {
      cout << arr[i].second << ' ' << arr[j].second << '\n';
      return 0;
    }
  }
  cout << "IMPOSSIBLE\n";

  return 0;
}