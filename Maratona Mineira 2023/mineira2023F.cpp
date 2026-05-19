/*
  Maratona Mineira 2023 - F - 14-bis 
  https://codeforces.com/group/YgJmumGtHD/contest/446227/problem/F
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  
  int n, m, x, ant;
  cin >> n >> m;
  vector<int> antCol(m), cntCol(m,1);
  
  int maiorLin = 1, maiorCol = 1;
  for (int i = 0; i < n; ++i) {
    int cntLin = 0;
    for (int j = 0; j < m; ++j) {
      cin >> x;
      
      // ver linha
      if (j <= 0) {
        ant = x;
        cntLin = 1;
      }
      else {
        if (abs(x-ant) <= 1)
         cntLin++;
        else
          cntLin = 1;
        maiorLin = max(maiorLin, cntLin);
      }
      ant = x;
      
      // ver Coluna
      if (i != 0){
        if (abs(x-antCol[j]) <= 1)
                cntCol[j]++;
        else
              cntCol[j] = 1;
        maiorCol = max(maiorCol, cntCol[j]);
      }
      antCol[j] = x;
    }
  }
  cout << max(maiorLin, maiorCol) << '\n';
  
  return 0;
}