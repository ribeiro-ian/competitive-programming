#include <bits/stdc++.h>
using namespace std;

typedef pair <string, int> psi;

bool cmp(psi a, psi b){return a.second > b.second;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <psi> nomes (n);
    for (int i = 0; i < n; i++)
        cin >> nomes[i].first >> nomes[i].second;
    sort(nomes.begin(), nomes.end(), cmp);
    
    vector <vector <string>> times (k);
    for (int i = 0; i < n; i++)
        times[i%k].push_back(nomes[i].first);
    
    for (int i = 0; i < k; i++){
        sort(times[i].begin(), times[i].end());

        if (i) printf("\n");
        printf("Time %i\n", i+1);
        for (auto &a : times[i])
            cout << a << endl;
    }

    return 0;
}
