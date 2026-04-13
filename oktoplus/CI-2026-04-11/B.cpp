/*
    Beecrowd 1069 - Diamantes e Areia
    https://judge.beecrowd.com/pt/problems/view/1069
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    
    stack<char> st;
    int cnt = 0;
    for (auto &c : s) {
        if (c == '<')
            st.push(c);
        else if (c == '>') {
            if (!st.empty()) {
                cnt++;
                st.pop();
            } 
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}