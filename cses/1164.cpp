/*
 * Contest : CSES Problem Set
 * Problem : 1164 - Room Allocation
 * Link    : https://cses.fi/problemset/task/1164
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n; cin >> n;
  vector<vector<int>> events;

  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;

    events.push_back({a, 1, i});
    events.push_back({b, 2, i});
  }
  sort(events.begin(), events.end());

  vector<int> ans(n + 1),
      free; // no free room since no room is required atm
  int cnt = 0;
  for (const auto &e : events) {
    int id = e.back();
    if (e[1] == 1) {
      if (free.empty()) {    // if no free rooms => create a new one
        cnt++;               // create
        free.push_back(cnt); // add to free rooms
      }
      ans[id] = free.back(); // take most recent free room
      free.pop_back();       // not free anymore
    } else
      free.push_back(ans[id]); // taken room is now free
  }

  cout << cnt << '\n';
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];

  return 0;
}
