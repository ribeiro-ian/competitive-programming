/*
  CSES 2205 - Gray Code
  https://cses.fi/problemset/task/2205
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<string> ans;
map<string, bool> done;

void search(int n, string str) {
  if (ans.size() == (int)pow(2, n)) { return; }

  cout << str << '\n';
  done[str] = true;

  for (int i = n - 1; i >= 0; --i) {
    str[i] = (str[i] == '0' ? '1' : '0');

    if (!done[str]) search(n, str);

    str[i] = (str[i] == '0' ? '1' : '0');
  }
}

int main() {
  fastio

  int n; cin >> n;
  string str(n, '0');

  search(n, str);

  return 0;
}