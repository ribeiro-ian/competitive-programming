#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    string s1, s2;
    cin >> tc;
    while (tc--){
        cin >> s1 >> s2;

        swap(s1[0], s2[0]);
        cout << s1 << " " << s2 << endl;
    }

    return 0;
}
