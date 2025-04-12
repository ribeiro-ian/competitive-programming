/*
    Codeforces 1104B - Game with string
    https://codeforces.com/problemset/problem/1104/B
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    cin >> str;

    int cnt = 0;
    while (!str.empty()) {
        bool flag = false;
        for (int i = 0; i < str.size()-1; i++) {
            if (str[i] == str[i+1]) {
                cnt++;
                str.erase(str.begin()+i+1);
                str.erase(str.begin()+i);

                flag = true;
                break;
            }
        }

        if (flag) continue;

        break;
    }

    cout << (cnt % 2 == 1 ? "Yes" : "No") << "\n";
    cerr << cnt << '\n';

    return 0;
}