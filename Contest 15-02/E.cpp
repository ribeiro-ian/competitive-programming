#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main(){
    int n, k, x, y;

    while (1){
        cin >> n >> k;
        
        if (!n) break;
        
        bool flag = true;
        stack <pii> est;
        
        for (int i = 0; i < n; i++){
            cin >> x >> y;

            if (est.top().second <= x && !est.empty())
                est.pop();

            if (est.size() < k)
                est.push(make_pair(x, y));
            else{
                flag = false;
                break;
            }
        }
                
        while (!est.empty()){
            pii frente = est.top();
            est.pop();

            pii tras;
            if (!est.empty())
                tras = est.top();
            else
                break;
            
            if (frente.second > tras.second){
                flag = false;
                break;
            }
        }
        
        printf("%s\n", flag ? "Sim" : "Nao");
    }
    

    return 0;
}
