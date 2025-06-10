/*
    CSES 2165 - Tower of Hanoi
    https://cses.fi/problemset/tspiask/2165
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int n;
vector <pii> ans;

void search() {
    if ( == n) {
        return;
    }
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            ans.push_back( make_pair(i,j) );

            search();

            ans.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    return 0;
}