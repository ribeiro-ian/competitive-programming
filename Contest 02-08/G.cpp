/*
    Beecrowd 2065 - Fila do Supermercado
    https://judge.beecrowd.com/pt/problems/view/2065
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(nullptr);

    int n, m, var;
    queue <int> clients;
    priority_queue <int, vector<int>, greater<>> free;
    vector <pii> active;
    map <int, int> time;
    
    scanf("%i %i", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &var);
        free.push(i+1);
        time[i+1] = var;
    }
    
    for (int i = 0; i < m; i++)
    {
        scanf("%i", &var);
        clients.push(var);
    }

    int ans = 0;
    while (!clients.empty() || !active.empty()){
        int fastest = INT_MAX;

        while (!free.empty() && !clients.empty()){
            int id = free.top(),
                qtt = clients.front();
                
            active.push_back(make_pair(id, time[id]*qtt));
                
            free.pop();
            clients.pop();
        }
        
        for(auto &w : active) 
            fastest = min(w.second, fastest);
        ans += fastest;

        vector <pii> new_active;
        for (auto &w : active){
            w.second -= fastest;
            
            if (w.second <= 0)
                free.push(w.first);
            else
                new_active.push_back(w);
        }
        active = new_active;
    }

    printf("%i\n", ans);

    return 0;
}
