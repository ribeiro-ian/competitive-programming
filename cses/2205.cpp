/*
 * Contest : CSES Problem Set
 * Problem : 2205 - Gray Code
 * Link    : https://cses.fi/problemset/task/2205
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;
map<int, bool> done;

void back(string str, int val) {
  if (ans.size() == (1 << n)) return;

  cout << str << '\n';
  done[val] = true;

  for (int i = 0; i < n; ++i) {
    val += (str[i] == '0' ? 1 : -1) * (1 << i);
    str[i] = (str[i] == '0' ? '1' : '0');

    if (!done[val]) back(str, val);

    val += (str[i] == '0' ? 1 : -1) * (1 << i);
    str[i] = (str[i] == '0' ? '1' : '0');
  }
}

int main() {
  fastio

  cin >> n;
  string s(n, '0');
  back(s, 0);

  return 0;
}
