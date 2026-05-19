/*
 * Contest : Beecrowd
 * Problem : 2852 - Troca de Mensagens
 * Link    : https://judge.beecrowd.com/pt/problems/view/2852
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

string k, s;
inline void moveK(int &i) { i = (i + 1) % k.size(); }

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  else
    return false;
}

char change(char k, char c) {
  int dist = k - 'a';
  char res = (c + dist) % ('z' + 1);
  if (res < 'a') res += 'a';

  return res;
}

void solve() {
  getline(cin, s);

  int ki = 0;
  char letter = s.front();
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];

    if (c == ' ') letter = s[i + 1];
    else if (!isVowel(letter)) {
      s[i] = change(k[ki], c);
      moveK(ki);
    }
  }
  cout << s << '\n';
}

int main() {
  fastio

  cin >> k;
  int n; cin >> n;
  cin.ignore();

  while (n--) solve();

  return 0;
}