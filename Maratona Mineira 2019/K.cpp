/*
    Maratona Mineira 2019 - K - Cobra de Dominós
    https://codeforces.com/group/YgJmumGtHD/contest/102223/problem/K
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll N; cin >> N;
    ll E = (N + 1) * (N + 2) / 2;

    if(N % 2) E -= N/2;

    cout << E << '\n';

    return 0;
}