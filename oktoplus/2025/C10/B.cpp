/*
    Codeforces 200B - Drinks
    https://codeforces.com/problemset/problem/200/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector <int> p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    p.assign(n,0);
    double sum = 0;
    for (auto &i : p){
        cin >> i;
        sum += i;
    }

    printf("%.12f\n", sum/n);

    return 0;
}