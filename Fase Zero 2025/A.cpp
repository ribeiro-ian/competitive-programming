#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define srt(x) sort(all(x))
#define f0r(x) for(int i = 0; i < x; i++)
#define f1r(x) for(int i = 1; i < x; i++)
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;

int main() {
    int C, G; cin >> C >> G;

    if(C == 1){
        cout << "vivo e morto" << endl;
        return 0;
    }
    else{
        if(G == 1)
            cout << "vivo" << endl;
        else cout << "morto" << endl;
    }

    return 0;
}