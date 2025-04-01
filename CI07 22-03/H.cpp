/*
    Codeforces 499B - Lecture
    https://codeforces.com/problemset/problem/499/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    string str1, str2;
    int n, m;

    scanf("%i %i", &n, &m);
    map <string, string> words;
    for (int i = 0; i < m; i++) {
        cin >> str1 >> str2;
        words[str1] = str2;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> str1;

        if (str1.size() <= words[str1].size())
            cout << str1 << " ";
        else
            cout << words[str1] << " ";
    }

    return 0;
}