/*
    CSES 2420 - Palindrome Queries
    https://cses.fi/problemset/task/2420
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isPalindrome(string &s, int l, int r) {
    while (l <= r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s; cin >> s;

    while (m--) {
        int op; cin >> op;

        if (op == 1) {
            int k; char c;
            cin >> k >> c;
            s[k-1] = c;
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << (isPalindrome(s, a-1, b-1) ? "YES" : "NO") << '\n';
        }
    }


    return 0;
}