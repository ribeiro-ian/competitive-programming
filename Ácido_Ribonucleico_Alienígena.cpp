#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map <char,char> par = {
    {'B', 'S'},
    {'C', 'F'},
    {'S', 'B'},
    {'F', 'C'}
};

int main(){
    string str;

    while (cin >> str){
        stack <char> pilha;
        int cnt = 0;

        for (auto &c : str){

            if (!pilha.empty() && c == par[pilha.top()]){
                pilha.pop();
                cnt++;
            }
            else
                pilha.push(c);
        }
        
        printf("%i\n", cnt);
    }
    
    return 0;
}
