#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool buscar(vector <string> &ht, int t, string pl) {
    for (int i = ht.size()-t; i < ht.size(); ++i) {
        if (ht[i] == pl) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, p;
    cin >> n >> p;

    int tam = 0;
    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
        tam = max(vet[i], tam);
    }

    map<int, string> palavra;
    vector<bool> jogando(n, true);
    vector<string> ht;
    for (int i = 0; i < p; i++) {
        int num; string str;

        cin >> num >> str;
        palavra[num] = str;
        ht.push_back(str);
    }

    int qtt = n, cnt = 0, i = 0, j = 1;
    while(qtt > 1) {
        if (i >= n) i = 0;
        if (j > p) j = 1;

        if (!jogando[i]) {
            i++;
            continue;
        }

        string pl = palavra[j];
        
        if (vet[i] == 0 || find(ht.end()-vet[i], ht.end(), pl) == ht.end()) {
            cerr << "Saiu jogador " << i+1 << ". A palavra era: " << pl << "\n";
            jogando[i] = false;
            qtt--;
        }
        else {
            // string res = *find(ht.end()-vet[i], ht.end(), pl);
            // cerr << "palavra: " << pl << "\n";
            if (ht[ht.size()-1] != pl) ht.push_back(pl);
        }
        if (ht.size() > tam) ht.erase(ht.begin());

        i++;
        j++;
    }

    for (int i = 0; i < n; i++) {
        if (jogando[i]) cout << i+1 << endl; 
    }
    cout << palavra[j-1] << endl;

    return 0;
}