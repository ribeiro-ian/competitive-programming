#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

bool isPalindrome(ll l, ll r, string &str) {
  while (l < r) {
    if (str[l] != str[r]) { return false; }
    l++;
    r--;
  }
  return true;
}

int main() {
  fastio

  string str; cin >> str;

  ll n = (ll)str.size();

  ll l = 0, r = (ll)str.size() - 1, aux = 0;

  while (l < r) {
    if (str[l] == str[r]) {
      if (isPalindrome(l, r, str)) {
        aux = r - l + 1;
        break;
      }
    }
    l++;
  }

  ll ans = n - aux;
  if (aux == 0) ans--;

  return 0;
}