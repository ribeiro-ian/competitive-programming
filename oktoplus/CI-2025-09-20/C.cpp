/*
    Beecrowd 1045 - Tipos de Triângulos
    https://judge.beecrowd.com/pt/problems/view/1045
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    float in[3];
    cin >> in[0] >> in[1] >> in[2];
    sort(in, in+3);
    float a = in[2], b = in[1], c = in[0];
    float aa = a*a, aux = b*b+c*c;

    if (a >= b + c) {
        cout << "NAO FORMA TRIANGULO\n";
        return 0;
    }
    if (aa == aux) 
        cout << "TRIANGULO RETANGULO\n";
    else if (aa > aux) 
        cout << "TRIANGULO OBTUSANGULO\n";
    else
        cout << "TRIANGULO ACUTANGULO\n";

    
    set <float> s = {a,b,c};
    if (s.size() == 1) 
        cout << "TRIANGULO EQUILATERO\n";
    else if (s.size() == 2) 
        cout << "TRIANGULO ISOSCELES\n";
    
    return 0;
}