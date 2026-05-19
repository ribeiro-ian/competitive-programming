/*
 * Contest : Codeforces
 * Problem : 1104B - Game with string
 * Link    : https://codeforces.com/problemset/problem/1104/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string str; cin >> str;

  int cnt = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i < str.size(); i++) {
      if (str[i] == str[i - 1]) {
        cnt++;
        str.erase(i - 1, 2);

        flag = true;
        break;
      }
    }
  }

  cout << (cnt % 2 == 1 ? "Yes" : "No") << "\n";
  cerr << cnt << '\n';

  return 0;
}