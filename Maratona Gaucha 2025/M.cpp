#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isPalindrome(ll l, ll r, string &str) {
    while (l < r) {
        if (str[l] != str[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string str;
    cin >> str;

    ll n = (ll) str.size();

    ll l = 0, r = (ll) str.size()-1, aux = 0;

    while (l < r) {
        if (str[l] == str[r]) {
            if (isPalindrome(l,r, str)) {
                aux = r-l+1;
                break;
            }
        }
        l++;
    }
    
    ll ans = n-aux;
    if (aux == 0) ans--;
    
    cout << 4 4 1 2ans << '\n';
            
    return 0;
}