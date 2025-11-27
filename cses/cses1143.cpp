/*
    CSES 1143 - Hotel Queries
    https://cses.fi/problemset/task/1143
*/
 
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
vector<int> v(2*N), tree(4*N);
int n, m;
 
void upd(int i, int x) {
    tree[i] -= x;
    for (i /= 2; i >= 1; i /= 2)
        tree[i] = max(tree[2*i], tree[2*i + 1]);
}

int find(int r) {
    if (r > tree[1]) return -1;

    int i = 1; // root
    while (i < n) {
        if (tree[2*i] >= r) // go left
            i = 2*i;
        else if(tree[2*i+1] >= r)// go right
            i = 2*i + 1;
    }

    return i;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m;  
    for (int i = 0; i < n; ++i) 
        cin >> v[i]; 
    
    while (n & (n-1)) // n & (n-1) == 0 (is power of 2)
        n++;

    // build
    for (int i = 0; i < n; ++i)
        tree[i+n] = v[i];
    for (int i = n-1; i >= 1; --i)
        tree[i] = max(tree[2*i], tree[2*i + 1]);
 
    while (m--) {
        int r; cin >> r;

        int i = find(r);
        if (i == -1)
            cout << "0 ";
        else {
            upd(i, r);
            cout << i-n+1 << ' ';
        }
    }
    cout << '\n';
 
    return 0;
}