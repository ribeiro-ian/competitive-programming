/*
 * Contest : Beecrowd
 * Problem : 1361 - Desenhando o Edifício
 * Link    : https://judge.beecrowd.com/pt/problems/view/1361
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n; cin >> n;
  vector<int> red, blue;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x < 0) red.push_back(x);
    else
      blue.push_back(x);
  }
  sort(red.begin(), red.end());
  sort(blue.rbegin(), blue.rend());

  if (red.empty() || blue.empty()) {
    cout << "1\n";
    return;
  }

  int rn = red.size(), bn = blue.size();
  int i = 0, j = 0, cnt = 1, last;
  if (-red[0] > blue[0]) last = red[i++];
  else
    last = blue[j++];

  // red => negative, blue => positive
  while (i < rn && j < bn) {
    // last = red
    if (last < 0) {
      if (blue[j] < -last) last = blue[j], cnt++;
      j++;
    }
    // last = blue
    else {
      if (-red[i] < last) last = red[i], cnt++;
      i++;
    }
  }
  if (last < 0) {
    while (j < bn && blue[j] >= -last) j++;
    cnt += j < bn;
  }
  else {
    while (i < rn && -red[i] >= last) i++;
    cnt += i < rn;
  }

  cout << cnt << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}