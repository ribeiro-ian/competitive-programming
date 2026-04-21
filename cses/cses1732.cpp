/*
    CSES 1732 - Finding Borders
    https://cses.fi/problemset/task/1732
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prefix_function(string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    auto p = prefix_function(s);
    for (auto& i : p)
        cout << i << ' ';
    cout << endl;

    return 0;
}