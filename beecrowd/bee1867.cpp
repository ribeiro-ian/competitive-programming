/*
 * Contest : Beecrowd
 * Problem : 1867 - Maior Número de Um Algarismo
 * Link    : https://judge.beecrowd.com/pt/problems/view/1867
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int count(string s) {
  int sum = 0;
  for (auto &c : s) sum += c - '0';

  if (sum >= 10) return count(to_string(sum));
  return sum;
}

int main() {
  fastio

  string a, b;
  while (cin >> a >> b) {
    if (a == "0" && b == "0") break;

    int resA = count(a),
        resB = count(b);

    if (resA == resB) cout << "0\n";
    else if (resA > resB) cout << "1\n";
    else
      cout << "2\n";
  }

  return 0;
}