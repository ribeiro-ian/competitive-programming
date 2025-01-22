#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  string str;

  while (tc--){
    cin >> str;

    string ans;
    int len = str.length();

    if (len > 10){
      ans += str[0];

      ans += to_string(len-2);

      ans += str[len-1];
    }
    else ans = str;
    
    cout << ans << "\n";
  }

  return 0;
}
