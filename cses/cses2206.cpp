/*
    CSES 2206 - Pizzeria Queries
    https://cses.fi/problemset/task/2206
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 2e9;

int n, q;
vector<int> price(N);

struct SegmentTree {
    vector<int> tree;
    int size;
    
    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, INF);
    }
    
    void update(int idx, int val) {
        idx += size;
        tree[idx] = val;

        for (idx /= 2; idx >= 1; idx /= 2) 
            tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    }
    
    int query(int l, int r) {
        int ans = INF;
        for (l += size, r += size+1; l < r; l /= 2, r /= 2) {
            if (l & 1) ans = min(ans, tree[l++]);
            if (r & 1) ans = min(ans, tree[--r]);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) 
        cin >> price[i];
    
    // left_tree: stores price[i] - i
    // right_tree: stores price[i] + i
    SegmentTree left_tree(n), right_tree(n);
    
    for (int i = 0; i < n; i++) {
        left_tree.update(i, price[i] - i);
        right_tree.update(i, price[i] + i);
    }
    
    while (q--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            int k, x;
            cin >> k >> x;
            
            price[--k] = x;
            left_tree.update(k, price[k] - k);
            right_tree.update(k, price[k] + k);
        }
        else {
            int k;
            cin >> k;
            k--;
            
            // price[j] + (k - j) = (price[j] - j) + k
            int min_l = left_tree.query(0, k) + k;
            
            // price[j] + (j - k) = (price[j] + j) - k  
            int min_r = right_tree.query(k, n - 1) - k;
            
            cout << min(min_l, min_r) << '\n';
        }
    }
    
    return 0;
}