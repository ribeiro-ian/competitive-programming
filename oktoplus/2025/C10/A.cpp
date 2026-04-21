/*
    Codeforces 381A - Sereja and Dima
    https://codeforces.com/problemset/problem/381/A
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n;
    deque <int> cards;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cards.push_back(x);
    }

    int sereja = 0, dima= 0;
    bool turn = true;

    while(!cards.empty()) {
        int front = cards.front(),
            back = cards.back();
        int card = max(front, back);

        if (turn) {
            sereja += card;
        }
        else {
            dima += card;
        }

        if (front == card) {
            cards.pop_front();
        }
        else {
            cards.pop_back();
        }

        turn = !turn;
    }

    cout << sereja << " " << dima << "\n";

    return 0;
}