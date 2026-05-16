/*
  Maratona Mineira 2019 - F - Quem é o mentiroso?
  https://codeforces.com/group/YgJmumGtHD/contest/102223/problem/F
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 1e5 + 1;
map<string, int> id;
map<int, string> nome;
vector<int> sorteou[N], foiSorteadoPor[N], in(N), out(N);

int main() {
  fastio

  int n; cin >> n;
  for (int i = 1, j = 1; i <= n; ++i) {
    string a, b;
    cin >> a >> b;

    if (!id.count(a)) id[a] = j, nome[j++] = a;
    if (!id.count(b)) id[b] = j, nome[j++] = b;

    sorteou[id[a]].push_back(id[b]);
    foiSorteadoPor[id[b]].push_back(id[a]);

    out[id[a]]++;
    in[id[b]]++;
  }
  /*  Todos devem ter grau de entrada e saida igual a 1.
      Os possiveis mentirosos quebram essa regra, para
      saber quem está mentindo deve remover cada
      um do jogo e ver se sem ele a regra é mantida
  */

  set<string> mentirosos;
  for (int i = 1; i <= (int)id.size(); ++i); // n resolvido

  cout << mentirosos.size() << '\n';
  for (auto &i : mentirosos) cout << i << '\n';

  return 0;
}