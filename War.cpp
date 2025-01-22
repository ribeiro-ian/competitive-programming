#include <bits/stdc++.h>
using namespace std;

const int MAX = 12345;
int n, c, x, y;
int friends[MAX];
vector <int> enemy[MAX];

int root(int x){
    if (friends[x] == x) return x;

    return friends[x] = root(friends[x]);
}

bool areFriends(int x, int y){
    return root(x) == root(y);
}

bool areEnemies(int x, int y){
    x = root(x); y = root(y);

    for (auto &e : enemy[x])
        if (root(e) == y)
            return true;

    return false;
}

int setFriends(int x, int y){
    x = root(x); y = root(y);

    if (areEnemies(x, y))
        return -1;
        
    friends[x] = y;
    enemy[y] = enemy[x];
}

int setEnemies(int x, int y){
    x = root(x); y = root(y);

    if (x == y)
        return -1;

    enemy[x].push_back(y);
    enemy[y].push_back(x);
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
        friends[i] = i;

    while (1){
        cin >> c >> x >> y;

        if (c == 0) break;

        if (c == 1)
            if (setFriends(x, y) == -1)
                cout << -1 << endl;
        if (c == 2)
            if (setEnemies(x, y) == -1)
                cout << -1 << endl;
        if (c == 3)
            cout << areFriends(x, y) << endl;
        if (c == 4)
            cout << areEnemies(x, y) << endl;

    }

    return 0;
}
