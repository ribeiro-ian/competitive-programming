#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int tc;
    cin >> tc;

    string str;
    while(tc--){
        cin >> str;
        
        bool flag = false;
        for (int i = 0; i < str.size()-1; i++){
            if (str[i] == str[i+1]){
                flag = true;
                break;
            }
        }

        if (flag)
            printf("1\n");
        else
            printf("%i\n", str.size());
    }

    return 0;
}
