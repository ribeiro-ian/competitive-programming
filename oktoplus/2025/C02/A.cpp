/*
  Beecrowd 1024 - Criptografia
  https://judge.beecrowd.com/pt/problems/view/1024
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio


  int tc; cin >> tc;
  cin.ignore();

  string str;
  while (tc--) {
    getline(cin, str);

    for (auto &c : str) {
      if (isalpha(c) && c != ' ') c += 3;
    }

    reverse(str.begin(), str.end());

    for (int i = str.size() / 2; i < str.size(); i++) str[i] -= 1;

    cout << str << endl;
  }

  return 0;
}
