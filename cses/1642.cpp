/**
 * Contest : CSES Problem Set
 * Problem : 1642 - Sum of Four Values
 * Link    : https://cses.fi/problemset/task/1642
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

#define F first
#define S second

int main() {
  fastio

  ll n, x;
  cin >> n >> x;

  vector<pair<ll, ll>> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].F;
    arr[i].S = i + 1;
  }
  sort(arr.begin(), arr.end());

  for (int j = 0; j < n - 3; ++j) {
    x -= arr[j].F;

    for (int i = j + 1; i < n - 2; ++i) {
      int l = i + 1, r = n - 1;

      x -= arr[i].F;
      while (l < r) {
        ll sum = arr[l].F + arr[r].F;

        if (sum == x) {
          cout << arr[j].S << ' '
               << arr[i].S << ' '
               << arr[l].S << ' '
               << arr[r].S << '\n';
          return 0;
        }
        if (sum > x) r--;
        else if (sum < x) l++;
      }
      x += arr[i].F;
    }
    x += arr[j].F;
  }
  cout << "IMPOSSIBLE\n";

  return 0;
}
