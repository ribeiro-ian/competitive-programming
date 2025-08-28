/*
    CSES 1140 - Projects
    https://cses.fi/problemset/task/1140
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    ll in, out, money;
} project;

bool cmp(project a, project b) {
    if (a.out != b.out) return a.out < b.out;
    if (a.in != b.in) return a.in < b.in;
    return a.money > b.money;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <project> v(n);
    for (auto &i : v) cin >> i.in >> i.out >> i.money;

    sort(v.begin(), v.end(), cmp);

    vector <ll> dp(n);
    for (int i = 0; i < n; ++i) {
        
    }



    return 0;
}