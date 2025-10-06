#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isLucky(int x) {
    string str = to_string(x);

    for (char c = '0'; c <= '9'; ++c) {
        if (c == '4' || c == '7') continue;

        if (str.find(c) != str.npos) 
            return false;
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    char c;
    int cnt = 0;
    while (cin >> c) {
        if (c == '4' || c == '7') 
            cnt++;
    }
    
    cout << (isLucky(cnt) ? "YES" : "NO") << '\n';

    return 0;
}