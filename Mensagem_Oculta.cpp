#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc;
    cin.ignore();

    while (tc--){
        string res, str;

        getline(cin, str);

        for (int i = 0; i < str.size(); i++){
            if (str[i] < 'a' || str[i] > 'z')
                continue;

            if (str[i-1] == ' ' || i == 0)
                res += str[i];
        }
        
        cout << res << endl;
    }

    return 0;
}
