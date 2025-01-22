#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
int n, q, x;
vector <int> h;

int lower_bound(int x){
    int l = 0, r = h.size();

    while (l + 1 < r){
        int mid = (l+r)/2;

        if (h[mid] >= x)
            r = mid - 1;
        else
            l = mid;
    }

    if (l >= h.size())
        return -1;

    return h[l];
}
int upper_bound(int x){
    int l = 0, r = h.size();

    while (l < r){
        int mid = (l+r)/2;

        if (h[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }

    if (l >= h.size())
        return -1;

    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        h.push_back(x);
    }
    
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> x;
        
        int ans = lower_bound(x);
        cout << ans << " ";

        ans = upper_bound(x);
        cout << ans << "\n";

    }

    return 0;
}
