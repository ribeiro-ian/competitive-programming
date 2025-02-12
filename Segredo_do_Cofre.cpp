#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> v(n+1, 0), pos(m+1,0), ans(MAX, 0);
    vector <vector <int>> pref(MAX);
    
    for (int i = 0; i < MAX; i++)
        pref[i].resize(n+1, 0);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++){

        for (int j = 0; j < MAX; j++)
            pref[j][i] = pref[j][i-1];

        pref[v[i]][i]++;
    }

    for (int i = 1; i <= m; i++)
        cin >> pos[i];

    for (int i = 0; i < m; i++){
        int atual = pos[i], prox = pos[i+1];

        for (int j = 0; j < MAX; j++){
            ans[j] += abs(pref[j][atual] - pref[j][prox]);

            if (atual > prox){
              if (v[atual] == j) ans[j]--;

              if (v[prox] == j) ans[j]++;
            }
        }
    }

    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    
    return 0;
}
