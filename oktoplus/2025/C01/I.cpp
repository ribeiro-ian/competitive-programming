/*
    Beecrowd 2410 - Frequencia na Aula
    https://judge.beecrowd.com/pt/problems/view/2410
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x ;
    cin >> n;

    set <int> s;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        s.insert(x);
    }
    
    printf("%i\n", s.size());

    return 0;
}
