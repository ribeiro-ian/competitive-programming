#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 1e5;

    cout << n << "\n";
    for (int i = 0; i < n/2; i++) {
        cout << i*2 << " " << i*2 << " " << (n-i)*2 << " " << (n-i)*2 << "\n";
    }
}

/*
1 3 3 2 1 1 6 2

*/