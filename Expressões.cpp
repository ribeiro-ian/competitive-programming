#include <bits/stdc++.h>
using namespace std;

bool solve(){
    stack <char> s;
    map <char, char> match{
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    string str;
    cin >> str;

    if (str.size() % 2)
        return false;
    
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            s.push(str[i]);
        
        else { // }])
            if (s.empty()) return false;

            if (s.top() != match[str[i]])
                return false;
        
            s.pop();
        }
    }

    if (!s.empty()) return false;

    return true;
}

int main(){
    int t; cin >> t;
    while (t--)
        cout << ( solve() ? "S" : "N" ) << endl;

    return 0;
}
