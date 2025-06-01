#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isBinaryPalindrome(int x) {
    int rev = 0, temp = x;

    while (temp > 0) {
        rev = (rev << 1) | (temp & 1); // Append LSB to rev
        temp >>= 1; // Shift temp right
    }

    return x == rev; // Compare reversed with original
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ull x;
    cin >> x;

    string str = bitset<64>(x).to_string();

    int l = 0, r;
    while (str[l] == '0') l++;

    for (r = str.size()-1; l < r; --r, ++l) {
        ll a = str[l] - '0';
        ll b = str[r] - '0';

        
    }

    return 0;
}