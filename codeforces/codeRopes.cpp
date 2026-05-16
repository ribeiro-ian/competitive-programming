/*
  Codeforces - Ropes
  https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, k, v[11234];

bool isValid(double x) {
  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += v[i] / x;
  return cnt >= k;
}

double bs() {
  double l = 0, r = 1e7, m, ans = 0;

  for (int i = 0; i < 100; i++) {
    m = (r + l) / 2;

    if (isValid(m)) {
      ans = m;
      l = m;
    } else
      r = m;
  }

  return ans;
}

int main() {
  fastio


  scanf("%i%i", &n, &k);

  for (int i = 0; i < n; i++) scanf("%i", &v[i]);

  printf("%f", bs());

  return 0;
}
