/*
    CSES 1622 - Creating Strings
    https://cses.fi/problemset/task/1622
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    vector <string> ans;
    do {
        ans.push_back(s);
    }
    while(next_permutation(s.begin(), s.end()));

    cout << (int) ans.size() << '\n';
    for (auto &str : ans)
        cout << str << '\n';

    return 0;
}