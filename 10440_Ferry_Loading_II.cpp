#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int tc, n, t, m, x;
vector <int> cars;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--){
        int pos = 0, time = 0, trips = 0;
        cin >> n >> t >> m;

        cars.clear();
        for (int i = 0; i < m; i++){
            cin >> x;
            cars.push_back(x);
        }

        sort(cars.begin(), cars.end());
        if (m % n == 0)
            time = cars[n-1]+2*t, pos = n;
        else
            time = cars[m % n - 1] + 2*t, pos = m % n;
        trips++;

        int cnt = 0;
        while (pos < cars.size()){
            time = max(cars[pos], time);

            pos++, cnt++;

            if (cnt == n){
                cnt = 0;
                trips++;
                time += 2 * t;
            }
        }
        time -= t;

        cout << time << " " << trips << endl;
    }
    

    return 0;
}
