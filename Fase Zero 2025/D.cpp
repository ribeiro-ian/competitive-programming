#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    string s, t;
    
    cin >> s; // estado isolado
    cin >> t; // cond normais
    
    int colapsa = 0,
        super = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') super++;
        if (s[i] == '*' && t[i] != '*') {
            colapsa++;
        }
    }

    printf("%.2f\n", (double) colapsa / (double) super);

    return 0;
}