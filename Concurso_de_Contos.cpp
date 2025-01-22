#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, c, l;
string str;

void solve(){
    int cnt = 0, linha = 0;

    for (int i = 0; i < n; i++){
        cin >> str;
        cnt += str.size();

        if (cnt + 1 <= c) // espaço dps da palavra
            cnt++;

        if (cnt >= c){
            linha++;
            
            if (cnt != c){ // se a palavra foi cortada, coloca na prox linha
                cnt = str.size();

                if (cnt + 1 <= c) // espaço dps da palavra
                    cnt++;
            }
            else cnt = 0; // nenhuma palavra cortada
        }
    }
    if (cnt != 0) linha++; // se sobraram palavras, +1 linha

    int pag = linha / l;
    
    if (linha % l != 0)
        pag++;
        
    cout << pag << endl; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> l >> c){
        if (n == EOF) break;
        solve();
    }
    
    return 0;
}
