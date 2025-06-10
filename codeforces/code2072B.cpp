/*
    Codeforces 2072B - Having Been a Treasurer in the Past, I Help Goblins Deceive-
    https://codeforces.com/contest/2072/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int tc, n;
    string str;
    scanf("%i", &tc);
    
    while(tc--){
        scanf("%i", &n);
        cin >> str;

        ll cnt_under = count(str.begin(), str.end(), '_');
        ll cnt_hyphen = count(str.begin(), str.end(), '-');

        ll ans = (cnt_hyphen/2) * cnt_under * ((cnt_hyphen/2) + (cnt_hyphen % 2 == 1));
        
        printf("%lli\n", ans);
    }

    return 0;
}