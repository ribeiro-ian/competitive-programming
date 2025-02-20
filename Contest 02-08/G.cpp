#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> clients;
    map<int, int> cashiers;
    map<int, int> active;
    set<int> inactive;
    int total = 0;

    for(int i = 0; i < n; i++) {
        cin >> cashiers[i];
        inactive.insert(i);
    }

    while(m--) {
        int c;
        cin >> c;

        clients.push(c);
    }

    while(!clients.empty() || !active.empty()) {
        int fastestWorker = INT32_MAX;
        set<int>::iterator hpc = inactive.begin();

        while(!inactive.empty() && !clients.empty()) {
            active[*hpc] = clients.front() * cashiers[*hpc];

            inactive.erase(hpc);
            hpc = inactive.begin();
            clients.pop();
        }

        for(auto rest : active) {
            if (rest.second < fastestWorker) {
                fastestWorker = rest.second;
            }
        }

        total += fastestWorker;
        vector<map<int, int>::iterator> done;

        for(map<int, int>::iterator it = active.begin(); it != active.end(); it++) {
            (*it).second -= fastestWorker;

            if((*it).second == 0) {
                inactive.insert((*it).first);
                done.push_back(it);
            }
        }

        for(int i = 0; i < done.size(); i++) {
            map<int, int>::iterator it = done[i];
            active.erase((*it).first);
        }
    }

    cout << total << '\n';

    return 0;
}