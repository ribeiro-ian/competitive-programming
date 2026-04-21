/*
    Beecrowd 2720 - Presentes Grandes
    https://judge.beecrowd.com/pt/problems/view/2720
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;

bool cmp(pii a, pii b){
    if (a.second != b.second)
        return a.second > b.second;

    return a.first < b.first;
}

int main(){

    ll tc, n, k, id, h, w, l;
    scanf("%lli", &tc);

    while(tc--){
        scanf("%lli %lli", &n, &k);
        
        vector <pii> gifts(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lli %lli %lli %lli", &id, &h, &w, &l);
            
            gifts[i] = {id, h*w*l};
        }
        
        sort(gifts.begin(), gifts.end(), cmp);
        
        vector <ll> ans (k);        
        for (int i = 0; i < k; i++){
            ans[i] = gifts[i].first;
        }
        sort(ans.begin(), ans.end());

        for(int i = 0; i < k-1; i++){
            printf("%lli ", ans[i]);
        }
        printf("%lli\n", ans[k-1]);
    }

    return 0;
}
