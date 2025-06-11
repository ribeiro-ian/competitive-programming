/*
    Beecrowd 2835 - Elevador
    https://judge.beecrowd.com/pt/problems/view/2835
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n;
    cin >> n;
    
    vector <int> v(n+1, 0);

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    char ans = 'S';
    for (int i = 0; i < n; i++)
    {
        if (v[i+1]-v[i] > 8){
            ans = 'N';
            break;
        }
    }
    
    printf("%c\n", ans);

    return 0;
}
