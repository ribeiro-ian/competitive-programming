#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, sum = 0;
    cin >> n;

    stack <int> nums;
    for (int i = 0; i < n; i++){
        cin >> x;

        if (x == 0){
            sum -= nums.top();
            nums.pop();
            continue;
        }

        sum += x;
        nums.push(x);
    }
    
    cout << sum << endl;

    return 0;
}
