/*
    Codeforces 1703B - ICPC Balloons
    https://codeforces.com/problemset/problem/1703/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int tc, n;
    string str;

    scanf("%i", &tc);
    while (tc--) {
        scanf("%i", &n);
        cin >> str;

        set <int> s;
        for (auto c : str) {
            s.insert(c);
        }

        printf("%i\n", s.size()*2 + str.size()-s.size());
    }

    return 0;
}