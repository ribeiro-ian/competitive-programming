/*
  Beecrowd 1029 - Fibonacci, Quantas Chamadas?
  https://judge.beecrowd.com/pt/problems/view/1029
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int cnt;
int fib(int x) {
  cnt++;
  if (x == 0) return 0;
  if (x == 1) return 1;

  return fib(x - 1) + fib(x - 2);
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;

    cnt = 0;
    int ans = fib(n);

    printf("fib(%i) = %i calls = %i\n", n, cnt - 1, ans);
  }

  return 0;
}
