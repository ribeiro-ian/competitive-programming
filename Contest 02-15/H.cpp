/*
    Bee 1579 - Transporte de Painéis Solares
    https://judge.beecrowd.com/pt/problems/view/1579
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    
    int tc, n, c, f;
    cin >> tc;
    
    while (tc--)
    {
        cin >> n >> c >> f;
        
        vector <int> p(n), cam(c, 0);

        int total = 0;
        for (int i = 0; i < n; i++){
            cin >> p[i];
            total += p[i];
        }

        int media = total / c;
        
        int i, j;
        for (i = 0, j = 0; i < n; i++){
            if (cam[j] + p[i] > media){
                j++;
            }
            if (j>=c){
                j--;
                break;
            }
            cam[j] += p[i];
        }

        while (i < n){
            cam[j] += p[i];
            i++;
        }

        int maior = *max_element(cam.begin(), cam.end());
        printf("%i $%i\n", maior, maior*f*c);
    }
    

    return 0;
}
