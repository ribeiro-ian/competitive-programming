/*
  Codeforces 734A - Anton and Danik
  https://codeforces.com/problemset/problem/734/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  int n;
  string str; cin >> n;

  cin >> str;
  int anton = 0, danik = 0;
  for (auto &c : str) {
    if (c == 'A') anton++;
    else
      danik++;
  }

  if (anton == danik) cout << "Friendship\n";
  else if (anton > danik) cout << "Anton\n";
  else
    cout << "Danik\n";

  return 0;
}