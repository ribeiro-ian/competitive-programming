/*
    CSES 3399 - Raab Game I
    https://cses.fi/problemset/task/3399
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, a, b;
vector <int> p1, p2;

bool isValid() {
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;

    for (int i = 0; i < p1.size(); ++i) {
        if (p1[i] > p2[i]) cnt1++;
        if (p2[i] > p1[i]) cnt2++;
    }

    return cnt1 == a && cnt2 == b;
}

bool solve() {
    cin >> n >> a >> b;
    
    p1.resize(n), p2.resize(n);
    for (int i = 0; i < n; ++i) p1[i] = p2[i] = i+1;
    
    if (a + b == 0) return true;
    if (a + b > n) return false;
    
    do {
        do {
            if (isValid()) {
                return true;
            }
        }
        while (next_permutation(p2.begin(), p2.end()));
        
        for (int i = 0; i < n; ++i) p2[i] = i+1;
    }
    while (next_permutation(p1.begin(), p1.end()));


    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        if (solve()) {
            cout << "YES\n";
            for (auto &i : p1)
                cout << i << ' '; cout << '\n';
            for (auto &i : p2)
                cout << i << ' '; cout << '\n';
        }
        else
            cout << "NO\n";
    }

    return 0;
}