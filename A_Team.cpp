#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc, ans = 0;
  cin >> tc;

  while (tc--){
    int x, cnt = 0;

    for (int i = 0; i < 3; i++){
      cin >> x;

      if (x==1) cnt++;
    }

    if (cnt >= 2) ans++;
  }

  cout << ans << "\n";

  return 0;
}
