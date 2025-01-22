#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, x, cnt = 0, v = 0;
  cin >> n >> k;

  for (int i = 0; i < n; i++){
    cin >> x;

    if (x <= 0)
      continue;

    if (i < k)
      cnt++;

    if (i == k-1)
      v = x;
    else if (x == v)
      cnt++;
  }

  cout << cnt << "\n";  

  return 0;
}
