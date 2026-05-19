/*
 * Contest : OBI 2017 - Fase 3
 * Problem : Arranha-céu
 * Link    : https://neps.academy/br/exercise/43
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 1;
int bit[MAXN], n, q;

// soma v em V[i]
void upd(int i, int v) {
  // lsb(i) = i&-i
  for (; i <= n; i += (i & -i)) bit[i] += v;
}

// soma de [1, i]
int sum(int i) {
  int ans = 0;

  for (; i > 0; i -= (i & -i)) ans += bit[i];

  return ans;
}

int main() {
  fastio

  cin >> n >> q;

  vector<int> vet(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> vet[i];
    upd(i, vet[i]);
  }

  while (q--) {
    int op, k, p;
    cin >> op >> k;

    if (op) {
      cout << sum(k) << "\n";
    }
    else {
      cin >> p;
      upd(k, p - vet[k]);
      vet[k] = p;
    }
  }

  return 0;
}