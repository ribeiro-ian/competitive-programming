#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    string str;

    cin >> str;
    int cnt_upper = 0, cnt_lower = 0;
    for (auto &c : str) {
        if (c == toupper(c)){
            cnt_upper++;
        }
        else
        cnt_lower++;
    }
    
    for (auto &c : str) {
        if (cnt_lower >= cnt_upper) 
            c = tolower(c);
        else
            c = toupper(c);
    }

    printf("%s\n", str.c_str());

    return 0;
}