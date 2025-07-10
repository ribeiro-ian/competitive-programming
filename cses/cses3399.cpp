/*
    CSES 3399 - Raab Game I
    https://cses.fi/problemset/task/3399
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, a, b, e;
vector <bool> chosen;
vector<int> permutation;

// a = 1, 2, 3, ..., n
void search(int v, int cntA, int cntB, int cntE) {
    if (permutation.size() == n) {
        for (int i = 1; i <= n; ++i) 
            cerr << i << ' ';
        cerr << '\n';
        for (auto i : permutation) 
            cerr << i << ' ';
        cerr << "\n";
        return;
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (chosen[i]) continue;
            if (cntA >= a && v > i) continue;
            if (cntB >= b && v < i) continue;
            if (cntE >= e && i == v) continue;

            if (v > i) cntA++;
            else if (v < i) cntB++;
            else cntE++;
            
            chosen[i] = true;
            permutation.push_back(i);
            search(v+1, cntA, cntB, cntE);
            
            if (v > i) cntA--;
            else if (v < i) cntB--;
            else cntE--;
            
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void solve() {
    cin >> n >> a >> b;
    e = n - a - b;
    if (a+b > n or (n%2==1 and (n==a or n==b))) {
        cout << "NO\n";
        return;
    }
    
    chosen.assign(n+1, false);
    search(1, 0, 0, 0);
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}