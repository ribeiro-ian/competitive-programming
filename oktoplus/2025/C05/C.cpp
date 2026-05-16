/*
  Beecrowd 1808 - O Retorno do Rei
  https://judge.beecrowd.com/pt/problems/view/1808
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string str; cin >> str;

  int total = 0, cnt = 0;
  for (auto c : str) {
    if (c == '0') total += 9;
    else
      cnt++;

    total += c - '0';
  }

  printf("%.2f\n", (double)total / cnt);

  return 0;
}
