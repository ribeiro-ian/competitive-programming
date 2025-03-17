/*
    Beecrowd 2065 - Fila do Supermercado
    https://judge.beecrowd.com/pt/problems/view/2065
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    int n, m, x, ans = 0;

    scanf("%i %i", &n, &m);

    map <int, int> time;
    priority_queue <int, vector <int>, greater <int>> free;
    vector <pair <int, int>> working;
    queue <int> clients;

    for (int i = 0; i < n; i++){
        scanf("%i", &x);

        time[i+1] = x;
        free.push(i+1);
    }
    for (int i = 0; i < m; i++){
        scanf("%i", &x);
        clients.push(x);
    }

    while (!clients.empty() || !working.empty()){
        while (!free.empty() && !clients.empty()){
            int id = free.top(), client = clients.front();
            
            working.push_back(make_pair(id, time[id] * client));
            
            free.pop();
            clients.pop();
        }
        
        int fastest = INT_MAX;
        for (auto w : working)
            fastest = min(fastest, w.second);
        
        ans += fastest;
        vector <pair <int, int>> new_working;
        for (auto &w : working)
        {
            w.second -= fastest;

            if (w.second <= 0){       
                free.push(w.first);
            }
            else{
                new_working.push_back(w);
            }
        }
        
        working = new_working;
    }
    
    printf("%i\n", ans);

    return 0;
}
