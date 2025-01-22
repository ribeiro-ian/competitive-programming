#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, x;
    cin >> n >> l;
    
    vector <int> cnt(n+1,0);
    vector <int> t(n+1,0);

    queue <int> lig;
    queue <int> v;

    for (int i = 1; i <= n; i++)
        v.push(i);

    for (int i = 0; i < l; i++){
        cin >> x;
        lig.push(x);
    }

    for (int i = 1; i <= n && !lig.empty(); i++){
        x = v.front();

        t[x] = lig.front();
        cnt[x]++;

        lig.pop();
        v.pop();
    }

    while (!lig.empty()){
        if (!v.empty()){
            x = v.front();
            
            t[x] = lig.front();
            cnt[x]++;

            lig.pop();
            v.pop();
            continue;
        }

        for (int i = 1; i <= n; i++){
            if (t[i]-1 == 0)
                v.push(i);
            if (t[i] > 0)
                t[i]--;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%i %i\n", i, cnt[i]);

    return 0;
}
