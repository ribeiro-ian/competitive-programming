#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    vector <int> v;
    set <int> s;
    queue <int> u;

    while (cin >> x){
        v.push_back(x);
        if (s.find(x) == s.end())
            u.push(x);
        s.insert(x);
    }

    while (!u.empty()){
        printf("%i %i\n", u.front(), count(v.begin(), v.end(), u.front()));
        u.pop();
    }

    return 0;
}
