/*
    CSES 2169 - Nested Ranges Count
    https://cses.fi/problemset/task/2169
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    int l, r, idx;
} range;

bool cmp(range a, range b) {
    if (a.l != b.l) 
        return a.l < b.l;
    return a.r > b.r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector <range> ranges(n);
    vector <int> contains(n), contained(n);

    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].idx = i;
    }

    sort(ranges.begin(), ranges.end(), cmp);
    int aux = 1e9+5;
    for (int i = n-1; i >= 0; --i) {
        if (ranges[i].r >= aux) {
            contains[ranges[i].idx] += 1;
        }
        aux = min(aux, ranges[i].r);
    }

    aux = 0;
    for (int i = 0; i < n; ++i) {
        if (ranges[i].r <= aux) {
            contained[ranges[i].idx] += 1;
        }
        aux = max(aux, ranges[i].r);
    }

    for (auto &i : contains)
        cout << i << ' ';
    cout << '\n';
    for (auto &i : contained)
        cout << i << ' ';
    cout << '\n';

    return 0;
}