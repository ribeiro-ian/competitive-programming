/*
    CSES 2163 - Josephus Problem II
    https://cses.fi/problemset/task/2163
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N = 2e5+1;
vector<bool> done(N, false);
vector<int> ans(N);
int n, k;

int pos(int x) {
    return (x%n == 0 ? n : x%n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    int st = ((1+k)%n ? (1+k)%n : n);
    
    cout << '\n';

    return 0;
}