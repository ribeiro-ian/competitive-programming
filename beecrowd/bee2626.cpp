/*
  Beecrowd 2626 - Turma do JB6
  https://judge.beecrowd.com/pt/problems/view/2626
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string s[3];
  map<string, string> oposto;
  oposto["tesoura"] = "pedra";
  oposto["pedra"] = "papel";
  oposto["papel"] = "tesoura";

  while (cin >> s[0] >> s[1] >> s[2]) {
    string ans;
    map<string, int> freq;
    for (auto &i : s) freq[i]++;

    if (freq.size() != 2) {
      ans = "Putz vei, o Leo ta demorando muito pra jogar...";
    }
    else {
      string um, dois;
      int id;
      for (int i = 0; i < 3; ++i) {
        string jogada = s[i];
        if (freq[jogada] == 1) {
          um = jogada;
          id = i;
        } else
          dois = jogada;
      }
      if (um == oposto[dois]) {
        if (id == 0) ans = "Os atributos dos monstros vao ser inteligencia, sabedoria...";
        else if (id == 1) ans = "Iron Maiden's gonna get you, no matter how far!";
        else
          ans = "Urano perdeu algo muito precioso...";
      } else
        ans = "Putz vei, o Leo ta demorando muito pra jogar...";
    }
    cout << ans << '\n';
  }

  return 0;
}