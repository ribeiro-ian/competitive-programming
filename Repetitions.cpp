#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    string str;
    cin >> str;

    int ans, cnt;
    ans = cnt = 0;
    for (int i = 0; i < str.size()-1; i++)
    {
        if (str[i] == str[i+1]){
            cnt++;
        }
        else{
            ans = max(ans, cnt+1);
            cnt = 0;
        }
    }
    ans = max(ans, cnt+1);
    printf("%i\n", ans);

    return 0;
}