/*
    Neps 65 - Mina
    https://neps.academy/br/exercise/65
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

vector <vector<int>> grid;

void dijkstra() {

    priority_queue <int, vector<int>, greater<int>> q;
    q.push();

    while (!q.empty()) {
        int curr = q.top();
        q.pop();

        if (grid[i][j]) continue;

        for ()
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    grid.assign(n+1, vector <int> (n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }


    

    return 0;
}