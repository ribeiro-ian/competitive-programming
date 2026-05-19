/*
 * Contest : Codeforces
 * Problem : 2065B - Skibidus and Ohio
 * Link    : https://codeforces.com/contest/2065/problem/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int tc; cin >> tc;

  string str;
  while (tc--) {
    cin >> str;

    bool flag = false;
    for (int i = 0; i < str.size() - 1; i++) {
      if (str[i] == str[i + 1]) {
        flag = true;
        break;
      }
    }

    if (flag) printf("1\n");
    else
      printf("%i\n", str.size());
  }

  return 0;
}
