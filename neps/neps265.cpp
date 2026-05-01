#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, l;
    cin >> n >> l;
    
    vector<int> cont(n+1,0);
    vector<int> tempo(n+1,0);

    queue<int> vendedores,
               ligacoes;

    for(int i = 1; i <= n; i++)
        vendedores.push(i); // todos vendedores inativos

    for(int i = 0; i < l; i++){
        int t; cin >> t;
        ligacoes.push(t);
    }


    // O(N)
    for(int i = 1; i <= n && !ligacoes.empty(); i++){
        int id = vendedores.front();

        tempo[id] = ligacoes.front();
        cont[id]++;

        ligacoes.pop();
        vendedores.pop();
    }

    // O(L)
    while (!ligacoes.empty()){
        if(!vendedores.empty()){
            int id = vendedores.front();
            
            tempo[id] = ligacoes.front();
            cont[id]++;

            ligacoes.pop();
            vendedores.pop();
        }
        else {
            // O(N)
            int menorTempo = 31;
            for(int i = 1; i <= n; i++)
                menorTempo = min(menorTempo, tempo[i]);

            for(int i = 1; i <= n; i++) {
                tempo[i] -= menorTempo;
                if(tempo[i] == 0) // vendedor esta livre
                    vendedores.push(i);
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << i << ' ' << cont[i] << '\n';

    return 0;
}
