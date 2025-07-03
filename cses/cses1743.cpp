/*
    CSES 1743 - String Reorder
    https://cses.fi/problemset/task/1743
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map <char, int> mp;
bool isValid(int n) {
    for (auto m : mp) {
        if (m.second > (n+1)/2) 
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    char c;
    int n = 0;

    while (cin >> c) {
        mp[c]++;
        n++;
    }
    
    char ant = 0;
    string ans = "";

    for (int i = 0; i < n; ++i) {
        bool flag = false;

        for (auto &it : mp) {
            c = it.first;
                        
            if (mp[c] <= 0 || c == ant) {
                continue;
            }

            mp[c]--;
            if (isValid(n-i-1)) {
                ans += c;
                ant = c;
                flag = true;
                break;
            }
            mp[c]++;
        }

        if (!flag) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
    cout << ans << '\n';

    return 0;
}