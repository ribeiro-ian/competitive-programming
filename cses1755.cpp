/*
    CSES 1755 - Palindrome Reorder
    https://cses.fi/problemset/task/1755
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string solve() {
    map <char, int> mp;
    char c;
    while (cin >> c) {
        mp[c]++;
    }

    int impar = 0;
    char meio = ' ';
    string ans = "";

    for (auto &m : mp) {
        if (m.second % 2 == 1) {
            if (impar)
                return "NO SOLUTION";

            impar++;
            meio = m.first;
        }
        else {
            for (int i = 0; i < m.second/2; ++i) {
                ans += m.first;
            }
        }
    }

    string ans2 = ans;
    reverse(ans2.begin(), ans2.end());
    
    string mid = "";
    if (meio != ' ') {
        for (int i = 0; i < mp[meio]; ++i) {
            mid += meio;
        }
    }

    return ans + mid + ans2;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cout << solve() << '\n';

    return 0;
}