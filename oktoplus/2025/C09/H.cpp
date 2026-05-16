/*
  Codeforces 208A - Dubstep
  https://codeforces.com/problemset/problem/208/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  string str; cin >> str;

  string word = "";
  for (auto &c : str) {
    word += c;

    if (word == "WUB") word.clear();
    else if (word.size() > 3 && word.substr(word.size() - 3, 3) == "WUB") {
      cout << word.substr(0, word.size() - 3) << ' ';
      word.clear();
    }
  }
  if (!word.empty()) cout << word << ' ';
  cout << '\n';

  return 0;
}