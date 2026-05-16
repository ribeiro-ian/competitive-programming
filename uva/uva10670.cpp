/*
  UVA 10670 - Work Reduction
  https://vjudge.net/problem/UVA-10670
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, int n, int target) {
  int cnt = 0;
  while (n > target) {
    if (n / 2 >= target) {
      cnt += min((n - n / 2) * a, b);
      n /= 2;
    }
    else {
      cnt += (n - target) * a;
      n = target;
    }
  }
  return cnt;
}

void solve(int c) {
  int n, m, l;
  cin >> n >> m >> l;

  vector<pair<int, string>> agency(l);
  for (int i = 0; i < l; ++i) {
    string in, name;
    int a, b; cin >> in;
    replace(in.begin(), in.end(), ':', ' ');
    replace(in.begin(), in.end(), ',', ' ');
    istringstream ss(in);
    ss >> name >> a >> b;
    agency[i] = {calc(a, b, n, m), name};
  }

  sort(agency.begin(), agency.end());
  cout << "Case " << c << '\n';
  for (auto &[cost, name] : agency) cout << name << ' ' << cost << '\n';
}

int main() {
  fastio
  int tc; cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
  return 0;
}