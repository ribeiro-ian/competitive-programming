#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    cin >> str;

    for (char c = '0'; c <= '9'; ++i) {
        cout << str.find(c) << '\n';
    }

    return 0;
}