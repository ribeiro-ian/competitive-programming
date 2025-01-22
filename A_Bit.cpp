#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc, ans = 0;
  cin >> tc;

  string str;
  while (tc--){
    cin >> str;

    if (str[1] == '+')
      ans++;
    else
      ans--;
  }
  
  cout << ans << "\n";

  return 0;
}
