#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, MAX = 10e5, cnt = 0;
vector <int> v (MAX);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    cin >> v[i];

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++)
            if (v[i] > v[j])
                cnt++;
    }

    cout << cnt << endl;

    return 0;
}