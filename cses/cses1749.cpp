/*
    CSES 1749 - List Removals
    https://cses.fi/problemset/task/1749
*/
 
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+1;
vector<int> tree(4*N), v(N);
int n;

void build() {
    for (int i = 0; i < n; ++i)
        tree[i+n] = (v[i]!=0);

    for (int i = n-1; i >= 1; --i) 
        tree[i] = tree[2*i] + tree[2*i+1];
}

void update(int i) {
    tree[i += n] = 0;
    for (i /= 2; i >= 1; i /= 2)
        tree[i] = tree[2*i] + tree[2*i+1];
}

int find(int idx) {
    int i = 1;

    while (i < n) {
        if (tree[2*i] >= idx)
            i = 2*i;
        else {
            idx -= tree[2*i];
            i = 2*i + 1;
        }
    }

    return i - n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    while (n & (n-1))
        n++;
    build();

    for (int i = 0; i < n; ++i) {
        if (!v[i]) break;
        int idx;
        cin >> idx;
        
        idx = find(idx);
        cout << v[idx] << ' ';
        
        update(idx);
    }
    cout << '\n';
 
    return 0;
}