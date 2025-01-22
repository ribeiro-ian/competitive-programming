#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> v(n), pref(n+1, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    pref[0] = 0;
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + v[i-1];

    cerr << "VETOR:\n   ";
    for (auto &&i : v)
        fprintf(stderr, "%2i ", i);
    cerr << "\n";
    for (auto &&i : pref)
        fprintf(stderr, "%2i ", i);
    cerr << "\n";

    int ans = 0, l = 0, r = 1;
    while (r <= n){
        ll diff = abs(pref[l] - pref[r]);

        fprintf(stderr, "l: %i | r: %i", l, r);
        if (diff == k)
            ans++;
        
        if (diff > k && l < r)
            l++;
        
        else
            r++;

        fprintf(stderr, " | cnt: %i \n", ans);
    }

    cout << ans << endl;

    return 0;
}
