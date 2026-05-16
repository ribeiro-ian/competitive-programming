/*
  Bee 1538 - Sequência Alienígena
  https://judge.beecrowd.com/pt/problems/view/1538
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n;

  string alien = "ABCD";
  while (1) {
    scanf("%i", &n);

    if (!n) break;

    int tmp = n * n;
    string ans = "";

    while (tmp != 0) {
      ans = alien[tmp % 4] + ans;
      tmp /= 4;
    }
    printf("%s\n", ans.c_str());
  }

  return 0;
}
