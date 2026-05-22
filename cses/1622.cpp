/*
 * Contest : CSES Problem Set
 * Problem : 1622 - Creating Strings
 * Link    : https://cses.fi/problemset/task/1622
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

string str;
vector<bool> pos(8, false);
set<string> words;

void back(string s) {
  if (s.size() == str.size()) {
    words.insert(s);
    return;
  }

  for (int i = 0; i < str.size(); ++i) {
    if (pos[i]) continue;

    s.push_back(str[i]);
    pos[i] = true;
    back(s);
    pos[i] = false;
    s.pop_back();
  }
}

int main() {
  fastio

  cin >> str;
  sort(str.begin(), str.end());
  back("");

  cout << words.size() << '\n';
  for (auto &s : words) cout << s << '\n';

  return 0;
}