/*
  Codeforces 4A - Watermelon
  https://codeforces.com/problemset/problem/4/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int w;
  scanf("%i", &w);

  printf("%s\n", (w % 2 == 0 && w > 2) ? "YES" : "NO");

  return 0;
}