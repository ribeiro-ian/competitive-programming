#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> v;

void solve(){
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(),v.end());
    rotate(v.begin(), v.begin()+(n%3), v.end());

    int sum = 0;
    for (int i = 0; i < n - (n%3); i++)
        if (i % 3 == 0)
            sum += v[i];

    printf("%i\n", sum);    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;

    while (tc--){
        solve();
    }

    return 0;
}
