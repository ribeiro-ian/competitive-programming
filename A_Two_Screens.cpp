#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, cnt, idx;
    string s1, s2;

    cin >> tc;
    while (tc--){
        cin >> s1 >> s2;

        cnt = idx = 0;

        while (s1[idx] == s2[idx] && idx < min(s1.size(), s2.size())){
            cnt++, idx++;
        }
        if (cnt) cnt++;
        
        cnt += s1.size() + s2.size() - 2*idx;

        cout << cnt << endl;
    }

    return 0;
}
